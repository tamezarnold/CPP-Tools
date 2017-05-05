//checks if a cstring is the same backward as forward

#include <iostream>
#include <string>


using namespace std;

bool eval(char a[]);

int main(){

	char a[40];

	cout << "Enter a string that you wish to be evaluated" << endl;
	cin >> a;

    bool palindrome = eval(a);

    if(palindrome == 1)
        cout << "Palindrome";
	else
        cout << "Not a Palindrome";

}

bool eval(char a[]){

	int alength = 1;
	while(*(a+alength) != '\0'){
		alength++;
	}

    bool palindrome = true;

    for(int counter = 0; counter < alength; counter++){
        if(*(a+counter) != *(a + alength- counter - 1)){
            palindrome = false;
            break;
            }
    }
return palindrome;
}
