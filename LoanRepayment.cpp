/*

This program will receive user input of the:

1. Principal amount borrowed
2. Annual interest rate
3. Total number of payments

and output the total amount repayed and how much each payment will have to be

*/

#include <iostream>

using namespace std;

// I created a power method because C++ does not come with one

double pow(double base, int power){

        double answer=1;
        int counter = power;

// I placed this condition to make sure if anyone places a payment less than or equal to zero it would be easy to catch
    if(counter <= 0) {
        counter = 0;
    }

	while(counter != 0){

		answer = answer * base;
		counter--;

	}
        return answer;
    }

int main()
{
	double Principal, Annual_Interest, Payments; //These are all of the variables that are initialized for user input
	double Total, Monthly_Interest, Payment_Amount; //These are the variables that are calculated from user input

    cout.setf(ios::fixed);
    cout.precision(2);

	cout << "Enter the pricipal amount borrowed \n";
	cin >> Principal;

	cout << "Enter the annual interest rate as a percentage \n (Ex: '10' would be 10%) \n";
	cin >> Annual_Interest;
	Monthly_Interest = (Annual_Interest / 1200) + 1; //now it is in terms of monthly interest

	cout << "What is the duration of the loan in years? \n";
	cin >> Payments;
    Payments= Payments*12; //now it is in terms of monthly payments

Payment_Amount= Principal * ( pow(Monthly_Interest,Payments) * (Monthly_Interest-1) ) / (pow(Monthly_Interest,Payments) - 1);

	Total = pow(Monthly_Interest,Payments) * Principal;

	cout << " \n Each payment will be $" << Payment_Amount << " for " << Payments << " monthly payments \n";
	cout << "The total amount of money that you will have paid is $" << Total << "\n";


return 0;
}


