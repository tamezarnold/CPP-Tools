//impliment string cancatination
//takes two cstrings as parameters and combines them

#include <iostream>
#include <string>

using namespace std;

char cstringcat( char a[], char b[]);

int main(){
	char a[20], b[20];

	cout << "Enter first string ";
	cin >> a;

	cout << "Enter second string ";
	cin >> b;

	cstringcat(a,b);


}

char cstringcat( char a[], char b[]){
	int alength = 0, blength = 0;
    char c[20];

		while(a[alength] != '\0'){
		c[alength] = a[alength];
		alength++;
	}
		while(b[blength] != '\0'){
		blength++;
	}
		for(int counter = 1; counter <= (blength+1); counter++){
			if(counter == 1)
                c[alength+counter] = ' ';

            c[alength+counter] = b[counter - 1];
		}

    for(int counter = 0; counter < (alength + blength + 1); counter++){

        cout << c[counter];
    }

return c;
}
