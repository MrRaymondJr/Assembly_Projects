/*--------------------------------------------------------------------
Purpose:	Solve a system of 2 equations wth two unkowns X and Y using Cramer's rule.
--------------------------------------------------------------------*/
#include <iostream>
using namespace std;

// Variables
int a, b, c, d, e, f, x, y;

// Display intro & inputs
void inputs()
{
	cout << "This program solves the system" << endl;
	cout << "   aX + bY = c" << endl;
	cout << "   dX + eY = f" << endl;
	cout << "Enter the values of a, b, and c: ";
	cin >> a >> b >> c;
	cout << "Enter the values of d, e, and f: ";
	cin >> d >> e >> f;
}

// Displays output
void output()
{
	cout << "   X = " << x << endl;
	cout << "   Y = " << y << endl;
}



int main()
{
	_asm
	{
		call	inputs;		// call inputs()

		// Finding X
			// Denominator
		mov		eax, a;		// eax = a
		imul	e;			// edx:eax = a * e
		mov		ebx, eax;	// ebx = a * e
		mov		eax, b;		// eax = b
		imul	d;			// edx:eax = b * d
		sub		ebx, eax;	// ebx = a * e - b * d
			// Numerator
		mov		eax, c;		// eax = c
		imul	e;			// eax = c * e
		mov		ecx, eax;	// ecx = c * e
		mov		eax, b;		// eax = b
		imul	f;			// eax = b * f
		sub		ecx, eax;	// ecx = c * e - b * f
			// Division
		mov		eax, ecx;	// eax = c * e - b * f
		cdq;				// edx:eax = c * e - b * f
		idiv	ebx;		// eax = (c * e - b * f) / (a * e - b * d)
		mov		x, eax;		// x = (c * e - b * f) / (a * e - b * d)

		// Finding Y
			// Denominator
		mov		eax, a;		// eax = a
		imul	e;			// edx:eax = a * e
		mov		ebx, eax;	// ebx = a * e
		mov		eax, b;		// eax = b
		imul	d;			// edx:eax = b * d
		sub		ebx, eax;	// ebx = a * e - b * d
			// Numerator
		mov		eax, a;		// eax = a
		imul	f;			// eax = a * f
		mov		ecx, eax;	// ecx = a * f
		mov		eax, c;		// eax = c
		imul	d;			// eax = c * d
		sub		ecx, eax;	// ecx = a * f - c * d
			// Division
		mov		eax, ecx;	// eax = a * f - c * d
		cdq;				// edx:eax = a * f - c * d
		idiv	ebx;		// eax = (a * f - c * d) / (a * e - b * d)
		mov		y, eax;		// x = (a * f - c * d) / (a * e - b * d)

		call	output;		// call output()
	}
	system("pause");
	return 0;
}
/*------------------------------Output--------------------------------
This program solves the system
   aX + bY = c
   dX + eY = f
Enter the values of a, b, and c: 3 1 1
Enter the values of d, e, and f: 1 -2 5
   X = 1
   Y = -2
Press any key to continue . . .
--------------------------------------------------------------------*/
