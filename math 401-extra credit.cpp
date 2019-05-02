#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
double  *mid_point(double []);
double  *trap_zoid(double []);
double *simpson(double []);
int main() {
    cout << left << setw(5) << "n" << right << setw(10) << "Midpoint Rule";
    cout << right << setw(20) << "Trapezoid Rule" << right << setw(20) << "Simpson's Rule" << endl;
    cout << "------------------------------------------------------------" << endl;
    double arr1[10],arr2[10],arr3[10];
    int j=2;
    simpson(arr3);
    mid_point(arr1);
    trap_zoid(arr2);
    for (int i =0; i< 10;i++){
        cout <<left << setw(5) <<  j << right << setw(10);
        cout << arr1[i] << right << setw(20) << arr2[i] << right << setw(20) <<  arr3[i] << endl;
        j = j+2;
    }
    
    system("Pause");
	
}
double *mid_point(double arr[]) {
    int counter =0;
    double *data;
	double delta;
    double total = 0;
	for (int i = 2; i <= 20; i = i + 2) {
		delta = 2.0 / i;
		data = new double[i];
		total = 0;
		for (int j = 0; j < i; j++) {
			data[0] = delta / 2;
			data[j + 1] = (data[j] + delta);
			total +=(1 / sqrt(1 + pow(data[j], 3)) *delta);
        }
        arr[counter] = total;
        counter++;
	}
    return arr;
}
double* trap_zoid(double arr[]) {
    int counter =0;
    double delta;
	double *data;
	double temp = 0.0;
	double total = 0.0;
	for (int i = 2; i <= 20; i = i + 2) {
		delta = 2.0 / i;
		total =  0.0;
		temp = 0.0;
		data = new double[i+1];
		for (int j = 0; j <= i; j++) {
			data[0] = 0;
			data[j + 1] = data[j]+delta;
			if (j==0||j == i)
				temp = (1 / sqrt(1 + pow(data[j] , 3)));
			else
				temp =  (2 / sqrt(1 + pow(data[j], 3)));
			total = total + temp;
		}
		total = delta/2 * total;
        arr[counter] = total;
        counter++;
    }
    return arr;

}
double *simpson(double arr[]) {
    double delta;
	double *data;
	double temp = 0.0;
	double total = 0.0;
    int counter =0;
        for (int i = 2; i <= 20; i = i + 2) {
            delta = 2.0 / i;
            total = 0.0;
            temp = 0.0;
            data = new double[i + 1];
            for (int j = 0; j <= i; j++) {
                data[0] = 0;
                data[j + 1] = data[j] + delta;
                if (j == 0 || j == i)
                    temp = (1 / sqrt(1 + pow(data[j], 3)));
                else if(j %2 == 0)
                    temp = (2 / sqrt(1 + pow(data[j], 3)));
                else
                    temp = (4 / sqrt(1 + pow(data[j], 3)));
                total = total + temp;
                }
            total = delta / 3 * total;
            arr[counter] = total;
            counter++;
            }
    return arr;
}
