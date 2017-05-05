/*Reads in .csv objects in a databse and
Responds to user requests or queries by outputting the record of the eligible table


sorted list by ID
Highest to lowest average q
Highest to lowest average t

If no objects match the specified conditions, the user must be notified
*/

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <fstream>
using namespace std;

struct table{//names of columns and type
    string LastName;
    string MiddleInitial;
    string FirstName;
    int ID;
    int qSorts[5];
    int tSorts[3];
};
int eval_length(string file_name);
int populate(string file_name,table p[]);
void menu(int choice,table p[], int list_length);
void LastName(table p[], int list_length);
void ID(table p[], int list_length);
void qSort(table p[], int list_length);
void tSort(table p[], int list_length);
void TestRange(table p[], int list_length, double lower_limit, double upper_limit);


int main(){

    string file_name;
    int choice;

    cout << "Enter the name of the file. \n";
    cin >> file_name;


    int list_length = eval_length(file_name);


    table *p;
    p = new table[list_length];

    populate(file_name, p);

    cout
    << "1) Sorted list of students by last name in ascending order. \n"
    << "2) Sorted list of students by ID number in ascending order. \n"
    << "3) Sorted list of students having the highest to lowest average quiz grade. \n"
    << "4) Sorted list of students having the highest to lowest average test grade. \n"
    << "5) Sorted list of students having an average test score within a specified range"
    << "6) Exit \n";
    cin >> choice;
    if(choice == 5){
        double lower_limit, upper_limit;
        cout << "Enter a lower limit: ";
        cin >> lower_limit;
        cout << endl;

        cout << "Enter an upper limit: ";
        cin >> upper_limit;
        cout << endl<< endl;

        TestRange(p, list_length, lower_limit, upper_limit);

    }
    else if( choice == 6){
        exit(0);
    }else{
        cout << endl << endl;
        menu(choice, p, list_length);
    }
main();
}
int eval_length(string file_name){


		ifstream infile;
		infile.open( file_name.c_str() );

		if ( !infile ){
		    cout << "The file could not be opened. \n";
			exit(1);
			}

		int size = 0;
		string line;

		while ( !infile.eof() )
		{
		getline(infile, line);
        size++;
		}
	return (size-2);
}
int populate(string file_name, table p[]){
  //  cout << "populate is running" << endl;
	ifstream infile;
	infile.open(file_name.c_str());

    if(infile.is_open()){

        int i = 0;

        while(!infile.eof()){
          //  cout << "i " << i << endl;
            infile
                >> p[i].LastName
                >> p[i].MiddleInitial
                >> p[i].FirstName
                >> p[i].ID;

            for(int x = 0; x < 5; x++){
                infile >> p[i].qSorts[x];
                }

            infile
                >>p[i].tSorts[0]
                >>p[i].tSorts[1]
                >>p[i].tSorts[2];

            i++;
        }


        infile.close();
        return (i-1); //list length
    }

    return -1;
}
void menu(int choice, table p[], int list_length){
    //cout << "list length " << list_length << endl;
    switch (choice){
        case 1:
            LastName(p,list_length);
            break;
        case 2:
            ID(p,list_length);
            break;
        case 3:
            qSort(p,list_length);
            break;
        case 4:
            tSort(p,list_length);
            break;
    }

}
void LastName(table p[], int list_length){
    //cout << list_length << endl;
    int gap_size, gap_control = 1,y,z;
    bool exchanges;
    table temp;

    char letter[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    //int number [26] ={1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26}
 do{
   exchanges = false;

    gap_size = pow(.5,gap_control)*list_length;
    //cout << "gap_control    " << gap_control << endl;
    //cout << "gap_size    " << gap_size << endl;

    if(gap_size < 1){
        gap_size = 1;}

        for(int x = 0; (x+gap_size) < list_length; x++){
           y = 0;
           z = 0;

               while (p[x].LastName[0] != letter[y]){
                y++;
               }
               while(p[x+gap_size].LastName[0] != letter[z]){
                z++;
               }


            if(y > z){
                exchanges = true;
                temp = p[x];
                p[x]= p[x + gap_size];
                p[x + gap_size] = temp;
            }
        }
		if(exchanges == false){
			gap_control++;
		}
    }while(gap_size > 1 || exchanges == true);

    for(int i =0; i < list_length; i++){
        cout
         << p[i].LastName
         << p[i].MiddleInitial
         << p[i].FirstName << " "
         << p[i].ID<< " "
         << p[i].qSorts[0]<< " "
         << p[i].qSorts[1]<< " "
         << p[i].qSorts[2]<< " "
         << p[i].qSorts[3]<< " "
         << p[i].qSorts[4]<< " "
         << p[i].tSorts[0]<< " "
         << p[i].tSorts[1]<< " "
         << p[i].tSorts[2]<< " "
          << endl;
    }

}
void ID(table p[], int list_length){
//cout << "ID is running \n";
int gap_size, gap_control = 1;
bool exchanges;
table temp;

do{
   exchanges = false;

    gap_size = pow(.5,gap_control)*list_length;

    if(gap_size < 1){
        gap_size = 1;}

        for(int x = 0; (x+gap_size) < list_length; x++){

            if( p[x].ID > p[x+gap_size].ID){
                exchanges = true;
                temp = p[x];
                p[x]= p[x + gap_size];
                p[x + gap_size] = temp;
            }
        }
		if(exchanges == false){
			gap_control++;
		}
    }while(gap_size > 1 || exchanges == true);

    for(int i =1; i < list_length; i++){
        cout
         << p[i].LastName
         << p[i].MiddleInitial
         << p[i].FirstName << " "
         << p[i].ID<< " "
         << p[i].qSorts[0]<< " "
         << p[i].qSorts[1]<< " "
         << p[i].qSorts[2]<< " "
         << p[i].qSorts[3]<< " "
         << p[i].qSorts[4]<< " "
         << p[i].tSorts[0]<< " "
         << p[i].tSorts[1]<< " "
         << p[i].tSorts[2]<< " "
          << endl;
    }


}
void qSort(table p[], int list_length){

    int gap_size, gap_control = 1;
    bool exchanges;
    table temp;
    double average, average_temp;

    double *QuizAverages;
    QuizAverages = new double[list_length];


    for(int i =0; i < list_length; i++){
        average = 0;
        for(int j = 0; j < 5; j++){
            average = average + p[i].qSorts[j];
        }
        QuizAverages[i] = average/5;
    }

    do{
       exchanges = false;

        gap_size = pow(.5,gap_control)*list_length;

        if(gap_size < 1){
            gap_size = 1;}

            for(int x = 0; (x+gap_size) < list_length; x++){

                if( QuizAverages[x] > QuizAverages[x+gap_size]){
                    exchanges = true;
                    temp = p[x];
                    p[x]= p[x + gap_size];
                    p[x + gap_size] = temp;

                    average_temp = QuizAverages[x];
                    QuizAverages[x]= QuizAverages[x + gap_size];
                    QuizAverages[x + gap_size] = average_temp;


                }
            }
            if(exchanges == false){
                gap_control++;
            }
        }while(gap_size > 1 || exchanges == true);

        for(int i = list_length - 1; i >= 0 ; i--){
            cout
             << p[i].LastName
             << p[i].MiddleInitial
             << p[i].FirstName << " "
             << p[i].ID<< " "
             << QuizAverages[i] << " "
              << endl;
        }

}
void tSort(table p[], int list_length){

    int gap_size, gap_control = 1;
    bool exchanges;
    table temp;
    double average, average_temp;

    double *TestAverages;
    TestAverages = new double[list_length];

    for(int i =0; i < list_length; i++){
        average = 0;
        for(int j = 0; j < 3; j++){
            average = average + p[i].tSorts[j];
        }
        TestAverages[i] = average/3;
    }

    do{
       exchanges = false;

        gap_size = pow(.5,gap_control)*list_length;

        if(gap_size < 1){
            gap_size = 1;}

            for(int x = 0; (x+gap_size) < list_length; x++){

                if( TestAverages[x] > TestAverages[x+gap_size]){
                    exchanges = true;
                    temp = p[x];
                    p[x]= p[x + gap_size];
                    p[x + gap_size] = temp;

                    average_temp = TestAverages[x];
                    TestAverages[x]= TestAverages[x + gap_size];
                    TestAverages[x + gap_size] = average_temp;


                }
            }
            if(exchanges == false){
                gap_control++;
            }
        }while(gap_size > 1 || exchanges == true);

        for(int i = list_length - 1; i >= 0 ; i--){
            cout
             << p[i].LastName
             << p[i].MiddleInitial
             << p[i].FirstName << " "
             << p[i].ID<< " "
             << TestAverages[i] << " "
              << endl;
        }



}
void TestRange(table p[], int list_length, double lower_limit, double upper_limit){
    int gap_size, gap_control = 1;
    bool exchanges;
    table temp;
    double average, average_temp;

    double *TestAverages;
    TestAverages = new double[list_length];

    for(int i =0; i < list_length; i++){
        average = 0;
        for(int j = 0; j < 3; j++){
            average = average + p[i].tSorts[j];
        }
        TestAverages[i] = average/3;
    }

    do{
       exchanges = false;

        gap_size = pow(.5,gap_control)*list_length;

        if(gap_size < 1){
            gap_size = 1;}

            for(int x = 0; (x+gap_size) < list_length; x++){

                if( TestAverages[x] > TestAverages[x+gap_size]){
                    exchanges = true;
                    temp = p[x];
                    p[x]= p[x + gap_size];
                    p[x + gap_size] = temp;

                    average_temp = TestAverages[x];
                    TestAverages[x]= TestAverages[x + gap_size];
                    TestAverages[x + gap_size] = average_temp;


                }
            }
            if(exchanges == false){
                gap_control++;
            }
        }while(gap_size > 1 || exchanges == true);

bool outputs = false;
        for(int i = list_length - 1; i >= 0 ; i--){
          if(TestAverages[i] > lower_limit && TestAverages[i] < upper_limit){
            cout
             << p[i].LastName
             << p[i].MiddleInitial
             << p[i].FirstName << " "
             << p[i].ID<< " "
             << p[i].qSorts[0]<< " "
             << p[i].qSorts[1]<< " "
             << p[i].qSorts[2]<< " "
             << p[i].qSorts[3]<< " "
             << p[i].qSorts[4]<< " "
             << p[i].tSorts[0]<< " "
             << p[i].tSorts[1]<< " "
             << p[i].tSorts[2]<< " "
             << "Tests Average "
             << TestAverages[i] << " "
              << endl;
              outputs = true;
          }
        }
        if(outputs == false){
            cout << "No students were in the specified range. \n";
        }



}




