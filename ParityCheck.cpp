#include <iostream>
using namespacestd;


int EvenOrOdd(Int Number);

int main(){

	int Number;
	
	cout<< "Enter a number -->";
	cin >> Number;

	int Result = EvenOrOdd(Number);
	
	if(Result == 1){
		cout << "Your number is even";
		
	}
	else{
		cout << "Your number is odd";
	}
	
	cout <<endl<<endln;
return 0;
}

int EvenOrOdd(Int Number){
	int Output;
	if( (Number % 2) == 0 ){
		Output = 1;
	}else {Output = 0}
	
	return Output;
}
