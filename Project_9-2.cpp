/*--------------------------------------------------------------
		Name:		Raymond Magdaleno
		Assignment:	9, Question 2
		Due Date:	1/30/2020

		Purpose:	Read values a, b, & c and compute both
					 real number roots from the quadratic
					 equation.
--------------------------------------------------------------*/
#include <iostream>
#include <iomanip>
using namespace std;

// Variables
float a, b, c, n0 = 0, n2 = 2, n4 = 4, x1, x2;

// Recieves user input
void inputs()
{
	cout << "Enter the values of a, b, and c: ";
	cin >> a >> b >> c;
}

// Displays output
void output()
{
	cout << "  Real number of X1 = " << x1 << endl;
	cout << "  Real number of X2 = " << x2 << endl;
}

int main()
{
	cout << fixed << showpoint << setprecision(2);
	_asm
	{
		call	inputs;	// Call inputs()

	findX1:
		fld		n0;		// st: 0
		fld		b;		// st: b | 0
		fsub;			// st: 0-b
		fld		b;		// st: b | -b
		fld		b;		// st: b | b | -b
		fmul;			// st: b*b | -b
		fld		n4;		// st: 4 | b*b | -b
		fld		a;		// st: a | 4 | b*b | -b
		fmul;			// st: 4*a | b*b | -b
		fld		c;		// st: c | 4*a | b*b | -b
		fmul;			// st: 4*a*c | b*b | -b
		fsub;			// st: b*b-4*a*c | -b
		fsqrt;			// st: sqrt(b*b-4*a*c) | -b
		fadd;			// st: -b+sqrt(b*b-4*a*c)
		fld		n2;		// st: 2 | -b+sqrt(b*b-4*a*c) 
		fld		a;		// st: a | 2 | -b+sqrt(b*b-4*a*c)
		fmul;			// st: 2*a | -b+sqrt(b*b-4*a*c)
		fdiv;			// st: -b+sqrt(b*b-4*a*c)/(2*a)
		fstp	x1;		// x1 = -b + sqrt(b^2-4*a*c) / (2*a)

	findX2:
		fld		n0;		// st: 0
		fld		b;		// st: b | 0
		fsub;			// st: -b
		fld		b;		// st: b | -b
		fld		b;		// st: b | b | -b
		fmul;			// st: b*b | -b
		fld		n4;		// st: 4 | b*b | -b
		fld		a;		// st: a | 4 | b*b | -b
		fmul;			// st: 4*a | b*b | -b
		fld		c;		// st: c | 4*a | b*b | -b
		fmul;			// st: 4*a*c | b*b | -b
		fsub;			// st: b*b-4*a*c | -b
		fsqrt;			// st: sqrt(b*b-4*a*c) | -b
		fsub;			// st: -b-sqrt(b*b-4*a*c)
		fld		n2;		// st: 2 | -b-sqrt(b*b-4*a*c) 
		fld		a;		// st: a | 2 | -b-sqrt(b*b-4*a*c)
		fmul;			// st: 2*a | -b-sqrt(b*b-4*a*c)
		fdiv;			// st: -b-sqrt(b*b-4*a*c)/2*a
		fstp	x2;		// x1 = -b - sqrt(b^2-4*a*c) / 2 * a

		call	output;	// Call output()
	}
	system("pause");
	return 0;
}
/*------------------------------Output--------------------------
Enter the values of a, b, and c: 2.1 4.5 1.7
  Real number of X1 = -0.49
  Real number of X2 = -1.65
Press any key to continue . . .
--------------------------------------------------------------*/