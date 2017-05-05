/*
1. Accepts an integer number from the user(N).
Generates N random numbers between 0 and 1 and writes these out to a file called DataFile.txt.
2. Calls the function double mymean (int N) that reads in the stored numbers from DataFile.txt
and returns their mean value to main().
3. Calls a function called double mysd (int N, double Mean) that reads in the stored numbers,
again from the file DataFile.txt, and returns their standard deviation to main().
Note that Mean is the mean value returned by mymean.
4. Writes out the returned mean and standard deviation to the console and to a file called DataStats.txt
*/

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fstream>

using namespace std;

double mymean (int N);
double mysd(int N, double mean);

int main(){

	ofstream Outfile;
	Outfile.open("DataFile.txt");

	int N;
	double Number,mean,standard_deviation;

	cout << "Enter the amount of random numbers you wish to be generate \n";
	cin >> N;

	for(int i = N; i  > 0; i--){
        Number = rand()% 100 + 1 ; //random numbers between .01 and 1 elminates the problem of dividing by 0
		Outfile << Number/100 <<endl;
}
    mean = mymean(N);
    standard_deviation = mysd(N,mean);

    cout << "The mean of the " << N << " random numbers is " << mean << "\n";
    cout << "The standard deviation of the numbers is " <<  standard_deviation;

	cout <<endl << endl;
return 0;
}

double mymean (int N){

	ifstream InStream("DataFile.txt"); // I realized afterward what you were asking me. This opens and names the file in one line.


	double sum = 0;
	double mean;
	double Number;


    while( InStream >> Number){
        sum = sum + Number;
    }
    mean = sum / N;

return mean;

}

double mysd(int N, double mean){
    ifstream InStream("DataFile.txt");

    double sum = 0;
    double Number,standard_deviation;
    double meandiff;

    while( InStream >> Number){
        meandiff = Number - mean;
        sum = sum + pow(meandiff,2);
    }
    standard_deviation = sqrt(sum/N);

    return standard_deviation;
}

