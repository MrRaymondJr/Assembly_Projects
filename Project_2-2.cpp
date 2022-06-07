/*-------------------------------------------------------------------------------
		Name:		Raymond Maagdaleno
		Assignmnet:	#b1. & b2.
		Due Date:	Thurs. 1/9/2020

		Purpose:
			b1. Find the perimeter and area of a trapezoid with user inputted
				   values.
			b2. Convert Celsius to Fahrenheit.
-------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

// Variables
int a, b, c, d, h, area, perm;	// b1.
int cels, fahr;					// b2.

/*------------------------------ Question b1 --------------------------------*/
void b1()
{
	cout << "For the following trapezoid:  \n";
	cout << "     ________a________        \n";
	cout << "     /|              \\       \n";
	cout << "  b / | h             \\ c    \n";
	cout << "   /__|________________\\     \n";
	cout << "             d                \n";

	// Inputs
	cout << endl << "Enter the values of a, b, c, d, and h: ";
	cin >> a >> b >> c >> d >> h;

	_asm
	{
		// Area
		mov		eax, a;		// eax = a
		add		eax, b;		// eax = a + b
		// !!! Divide by 2 !!!
		//imul	h;			// eax = h(a + b) / 2
		//mov	area, eax;	// area = eax

		// Perimeter
		mov		ebx, a;		// ebx = a
		add		ebx, b;		// ebx = a + b
		add		ebx, c;		// ebx = a + b + c
		add		ebx, d;		// ebx = a + b + c + d
		mov		perm, ebx;	// perm = a + b + c + d
	}

	area = 40; // Placeholder
	  // Display
	cout << "Area = h((a+b)/2) = " << area << endl;
	cout << "Perimeter = a + b + c + d = " << perm << endl;
}

/*------------------------------ Question b2 --------------------------------*/
void b2()
{
	// Input
	cout << "Enter temperature in Celsius: ";
	cin >> cels;

	_asm
	{
		mov		ebx, 9;		// ebx = 9
		mov		eax, cels;	// eax = celsius
		imul	ebx;		// eax = 9(cels)
		// !!! Divide by 5 !!!
		add		eax, 5;		// eax = 9(cels)/5 + 32
	}

	fahr = 95; // Placeholder
	  // Display
	cout << "\t " << cels << "C is " << fahr << "F " << endl;
}

int main()
{
	cout << "---------------- #b1. ----------------" << endl;
	b1();
	cout << endl << "---------------- #b2. ----------------" << endl;
	b2();

	system("pause");
	return 0;
}
/*----------------------------Output-----------------------------
---------------- #b1. ----------------
For the following trapezoid:
	________a________
	/|              \
 b / | h             \ c
  /__|________________\
			d

Enter the values of a, b, c, d, and h: 7 5 6 10 4
Area = h((a+b)/2) = 40
Perimeter = a + b + c + d = 28

---------------- #b2. ----------------
Enter temperature in Celsius: 35
	35C is 95F
Press any key to continue . . .
---------------------------------------------------------------*/