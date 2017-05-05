/*													
This program will prompt the user for the three coefficients (a, b, and c) of the quadratic equation.
The quadratic equation will be used to to compute and report the two roots (r1 and r2) as
(1) real and distinct,
(2) real and equal, or
(3) complex (g + hi or g - hi)

All outputs will be in fixed notation.
*/


#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

double realroots(double a, double b, double determinant );
double complexroots(double a, double b, double determinant );

int main(){

	cout.setf(ios::fixed);
    cout.precision(2);

    // for the equation ax^2 + bx + c;
	double a,b,c;


	cout << " \t Quadratic Equation Program \n";
	cout << " Enter 'a' 'b' and 'c' from the equation 'ax^2 + bx + c' \n";
	cout << "\n a = ";
	cin >> a;
	cout << "\n b = ";
	cin >> b;
    cout << "\n c = ";
	cin >> c;


	/*
	'a' must be tested in order to see if the equation is quadratic and
	'b^2 - 4ac' must be tested in order to determine if the roots
	 are real or imaginary
	 */

    double determinant = b*b-4*a*c;

	if(a == 0){
		cout << "The equation is not a quadratic";
	}
	else if( (determinant) >= 0){
		cout << "The roots are real. \n";
		realroots(a,b,determinant);
		}
	else if (determinant < 0){
		cout << "The roots are imaginary. \n";
		complexroots(a,b,determinant);
		}

return 0;
}
double realroots(double a, double b, double determinant ){

    double First_Root, Second_Root;

    First_Root = (-b + sqrt( determinant ) ) / (2*a);
	Second_Root = (-b - sqrt( determinant ) ) / (2*a);

    if( First_Root == Second_Root){
        cout << "The two roots are equal \n x = " << First_Root;
    }
    else{
    cout << "The roots are discrete. \n";
    cout << "x = " << First_Root << " and x = " << Second_Root;
    }
cout << endl << endl;
    return 0;
}
double complexroots(double a, double b, double determinant ){

    double imaginary_part, real_part;
/* I seperated the real part from the imaginary part by making sqrt(-(b*b - 4*a*c))real
	and adding 'i' to it later and by making the real part -b/2a
	*/

    imaginary_part= sqrt(-(determinant )) / (2*a); //  *i
    real_part = (-b / (2*a));
/*the two imaginary roots are complex conjugates
 I added this condition because if the real part is 0 then it looks weird if the answer
 is 0.00 + hi and 0.00 - hi
 */
if (real_part != 0){
    cout << "x = " << real_part << "+" << imaginary_part << "i";
    cout << " and x = "<< real_part << "-" << imaginary_part << "i";
    }
else{

    cout << "+" << imaginary_part <<"i and " << " -" << imaginary_part << "i";
    }
cout << endl << endl;
	return 0;
}
