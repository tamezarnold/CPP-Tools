/*
 Shell sorting technique
 Writes out both the generated list and the sorted list to a single file called “Sorted.txt” in a two-column format.
 Reports to the console which of the two techniques executed faster.*/

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <fstream>

using namespace std;

void Createlist();
int Homegrown();
int ShellSorting();
void Output();
void Compare_Outputs(int HG, int SS);


ofstream Outfile("Sorted.txt");
double A[10000][4];//multidemensional array for two-two-column outputs
int ListLength = 10000;

int main(){
        Createlist();
        int HG  = Homegrown();
        int SS = ShellSorting();
        Output();
        Compare_Outputs(HG, SS);
}
void Createlist(){

    //Generates a list of 10,000 random numbers in the interval -1.0 to 1.0.

    for(int x = 0; x < ListLength; x++){
        A[x][0] = ((rand()%100)*pow(-1,(rand()%2 + 1))/100);
		//somehow this didn't compile in visual studios... wtf
        //pow(-1,(rand()%2 + 1) dictates randomly whether the number will be positive or negative (-1)^k
        A[x][1]= A[x][0];
        A[x][2]= A[x][0];
        A[x][3]= A[x][0];
        //this is so that the sorting will not be done on the list with the generated numbers. They will stay the same
        //also the two different sorting techniques will be done on the same lists
    }
}
int Homegrown(){
    //find the smallest number in the list and swap it with the first number
    //in the list, then find the next smallest number and swaps it with the second number in the list,
    //continues until the list is sorted.

    clock_t start = clock();
    double Sorted[ListLength];
    double min;
    int min_pos;

    cout << "Homegrown: ";
    Outfile << "Homegrown: ";

    for(int counter = 0; counter < ListLength; counter++){
        min = A[counter][1];
        for (int i = counter; i < ListLength; i++){
            if (A[i][1] < min){
                min = A[i][1];
                min_pos = i;
                }
        }
        Sorted[counter] = min;
        A[min_pos][1] = A[counter][1];
        A[counter][1] = min;
    }

 clock_t HG_elapsed = clock() - start;
     cout << "The elapsed time was " << HG_elapsed << endl;
     Outfile << "The elapsed time was " << HG_elapsed << endl;

     return HG_elapsed;
}
int ShellSorting(){
/*repeatedly comparing and exchanging elements over a series of gaps until the array is arranged
in the specified order.
*/

clock_t start = clock();

int gap_size, gap_control = 1;
double temp;
bool exchanges;

Outfile << "ShellSorting Sorted: ";
cout << "ShellSorting: ";


do{
   exchanges = false;

    gap_size = pow(.5,gap_control)*ListLength;
    // since the  will keep going after the gap_size is already 1 of less than one
    // and it needs to repeat the shell with gap size 1
    // this if statement will catch it and set it back to 1
    if(gap_size < 1){
        gap_size = 1;}

   //cout << endl<< "gap_size = "<<gap_size << endl;

        for(int x = 0; (x+gap_size) < ListLength; x++){
            if(A[x][3] > A[x+gap_size][3]){
                exchanges = true;
                temp = A[x][3];
                //cout << " temp = " << temp;
                A[x][3] = A[x+gap_size][3];
                //cout << " A[x] = " << A[x];
                A[x+gap_size][3] = temp;
                //cout << " A[x+gap_size] = " << A[x+gap_size];
                //cout << endl;
            }
        }
       /*new list order
      for(int y = 0; y < ListLength; y++){
        cout << A[y][3] << ", ";}
        cout << endl;*/

		if(exchanges == false){
			gap_control++;
		}
    }while(gap_size > 1 || exchanges == true);


    clock_t SS_elapsed = clock() - start;
    cout << "The elapsed time was " << SS_elapsed << endl;
    Outfile << "The elapsed time was " << SS_elapsed << endl;

    return SS_elapsed;}
void Output(){
    Outfile << "\t Random Number List \t\t Sorted By Homegrown \t\t Random Number List \t\t Shell Sorted \n";
    for(int y = 0; y < ListLength; y++){
        for(int x = 0; x < 4; x++){
            Outfile << "\t\t" <<  A[y][x] << " \t\t ";
        }
        Outfile << endl;
    }

}
void Compare_Outputs(int HG, int SS){
    if(HG > SS){
        cout << "\n Shell Sorting executed faster \n";
        Outfile << "\n Shell Sorting executed faster \n";}
    if( HG < SS){
        Outfile << "\n Homegrown executed faster \n";
        cout << "\n Homegrown executed faster \n";}
    if(HG == SS){
        Outfile << "\n The two executed equally slow \n";
        cout << "\n The two executed equally slow \n";}

}
