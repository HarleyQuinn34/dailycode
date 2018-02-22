#include <iostream>
using namespace std;
int main(){
	int num;
	int num2;
	int num3;
	int num4;
	int num5;
	int sum;
	int sum2;
	int sum3;
	int sum4;
	int sum5;
	cout << "Type first number of base 2 number" << endl;
	cin >> num;
	cout << "Type second number of base 2 number" << endl;
	cin >> num2;
	cout << "Type third number of base 2 number" << endl;
	cin >> num3;
	cout << "Type fourth number of base 2 number" << endl;
	cin >> num4;
	cout << "Type last number of base 2 number" << endl;
	cin >> num5;

	sum5 = num5 * 16;
	sum = num * 8;
	sum2 = num2 * 4;
	sum3 = num3 * 2;
	sum4 = num4 * 1;
	cout << sum + sum2 + sum3 + sum4+ sum5 <<endl;

}