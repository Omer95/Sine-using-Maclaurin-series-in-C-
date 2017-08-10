/*
Author Omer Farooq Ahmed and Ammar Syed 
8/8/2017
TEST PROGRAM
This program calculates sine of an input value
using the maclaurin series to an accuracy of 0.001
*/
#include <iostream>
#include <cmath>
using namespace std;

double factorial (double value) {
	if (value<=1)
		return 1;
	else 
		return value*factorial(value-1);
}
int main() {
	//VARIABLES
	double newVal, oldVal;
	double power=3;
	double sign=1;	
	double x;
	int iteration=0;
	double diff;
	//PROGRAM
	cout << "Please enter a value x in radians: " <<endl;
	cin >> x;
	oldVal=x;
	//cout<< "Setup: "<<oldVal<<"\n";
	newVal=x-((pow(x, 3.0))/factorial(3));
	//cout<< "Setup: "<<newVal<<"\n";
	
	while (abs(newVal-oldVal) >= 0.001) {	
	
		oldVal+= (pow(-1.0, sign))*((pow(x, power))/factorial(power));
		//cout << iteration<<": "<<oldVal<<"\n";
		sign++;
		power+=2;
		newVal+= (pow(-1.0, sign))*((pow(x, power))/factorial(power));
		//cout << iteration<<": "<<newVal<<"\n";
		
		diff=newVal-oldVal;
		//cout<< abs(diff) << "\n\n";
		iteration++;	
	}
	
	cout << "\n The sine of " <<x<< " is " <<newVal <<"\n Calculated in "<<iteration<< " iterations"<<endl;
	
	
	
}
