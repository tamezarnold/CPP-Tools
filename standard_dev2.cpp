/*
Standard deviation of random numbers
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

using namespace std;

double mymean (double array[],int N);
double mysd(double array[],int N, double mean);

int main(){

	int N;
	double mean,standard_deviation;

	cout << "Enter the amount of random numbers you wish to be generate \n";
	cin >> N;

	double* array; //Declare pointer to type of array
    array = new double[N];

	for(int i = 0; i < N; i++){
		double Number = rand()% 100 + 1 ; //random numbers between .01 and 1 elminates the problem of dividing by 0
		array[i]= (Number/100);
}

    mean = mymean(array,N);
    standard_deviation = mysd(array,N,mean);

    cout << "The mean of the " << N << " random numbers is " << mean << "\n";
    cout << "The standard deviation of the numbers is " <<  standard_deviation;

	cout <<endl << endl;
return 0;
}

double mymean (double array[],int N){

	double sum = 0;
	double mean;


  for(int i = 0; i < N; i++){
		sum = sum + array[i];
}
    mean = sum / N;

return mean;

}

double mysd(double array[],int N, double mean){
    double sum = 0;
    double standard_deviation;

     for(int i = 0; i < N; i++){
        double meandiff = array[i] - mean;
        sum = sum + pow(meandiff,2);
    }
    standard_deviation = sqrt(sum/N);

    return standard_deviation;
}
