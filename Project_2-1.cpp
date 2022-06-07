/*-------------------------------------------------------------------------------
		Name:		Raymond Maagdaleno
		Assignmnet:	#a1-a4.
		Due Date:	Thurs. 1/9/2020

		Purpose:
			a1. Find area and perimeter of a rectangle with user input values.
			a2. Calculate a bill with different quantities of items.
			a3. Find the sum of digits of a three digit integer.
			a4. Convert Fahrenheit to Celsius.
-------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

// Variables
int leng, wid, perm, area;			// a1.
short sand, drink, chips, total;	// a2.
int digit, sum;						// a3.
int fahr, cels;						// a4.

/*------------------------------ Question a1 --------------------------------*/
void a1()
{
	cout << "For the following rectangle:     \n";
	cout << "  ___________________            \n";
	cout << " |                   |           \n";
	cout << " |                   | width     \n";
	cout << " |___________________|           \n";
	cout << "        length                   \n";
	cout << endl;

	// Inputs
	cout << "Enter the measure of width: ";
	cin >> wid;
	cout << "Enter the measure of length: ";
	cin >> leng;

	_asm
	{
		// Area
		mov		eax, wid;	// eax = width
		imul	leng;		// eax = width * length
		mov		area, eax;	// area = width * length

		  // Perimeter
		mov		ebx, wid;	// ebx = width
		add		ebx, leng;	// ebx = width + height
		add		ebx, ebx;	// ebx = 2(width) + 2(height)
		mov		perm, ebx;	// perm = 2(width) + 2(height)
	}

	// Display
	cout << "\t Area = " << area << endl;
	cout << "\t Perimeter = " << perm << endl;
}

/*------------------------------ Question a2 --------------------------------*/
void a2()
{
	cout << "-------K Store menu------- \n";
	cout << "  Sandwich...........$4    \n";
	cout << "  Drink..............$2    \n";
	cout << "  Chips..............$1    \n" << endl;

	// Input
	cout << "  How many sandwiches? ";
	cin >> sand;
	cout << "  How many drinks? ";
	cin >> drink;
	cout << "  How many chips? ";
	cin >> chips;
	cout << endl;

	_asm
	{
		// Sandwiches
		mov		ax, 4;		// ax = 4
		imul	sand;		// ax = 4(sand)
		mov		bx, ax;		// bx = 4(sand)
		  // Drinks
		mov		ax, 2;		// ax = 2
		imul	drink;		// ax = 2(drink)
		add		bx, ax;		// bx = 4(sand) + 2(drink)
		  // Chips
		mov		ax, 1;		// ax = 1
		imul	chips;		// ax = 1(chips)
		add		bx, ax;		// bx = 4(sand) + 2(drink) + 1(chips)
		  // Total
		mov		total, bx;	// total = 4(sand) + 2(drink) + 1(chips)
	}

	// Display
	cout << "\t Your total bill is $" << total << endl;
}

/*------------------------------ Question a3 --------------------------------*/
void a3()
{
	// Input
	cout << "Enter a three digit integer number: ";
	cin >> digit;

	_asm
	{
		// Divide the 1s, 10s, and 100s place to get each digit
	}

	sum = 11; // Placeholder
	  // Display
	cout << "Sum of digits in " << digit << " is " << sum << endl;
}

/*------------------------------ Question a4 --------------------------------*/
void a4()
{
	// Input
	cout << "Enter temperature in Fahrenheit: ";
	cin >> fahr;

	_asm
	{
		mov		eax, fahr;	// aex = fahr
		mov		ebx, 5;		// ebx = 5
		sub		eax, 35;	// aex = fahr - 35
		imul	ebx;		// aex = 5(fahr - 35)
		// Divide by 9
	}

	cels = 35; // Placeholder
	  // Display
	cout << fahr << "F is " << cels << "C" << endl;
}

int main()
{
	cout << "---------------- #a1. ----------------" << endl;
	a1();
	cout << endl << "---------------- #a2. ----------------" << endl;
	a2();
	cout << endl << "---------------- #a3. ----------------" << endl;
	a3();
	cout << endl << "---------------- #a4. ----------------" << endl;
	a4();

	system("pause");
	return 0;
}
/*----------------------------Output-----------------------------
---------------- #a1. ----------------
For the following rectangle:
  ___________________
 |                   |
 |                   | width
 |___________________|
		length

Enter the measure of width: 23
Enter the measure of length: 44
		 Area = 1012
		 Perimeter = 134

---------------- #a2. ----------------
-------K Store menu-------
  Sandwich...........$4
  Drink..............$2
  Chips..............$1

  How many sandwiches? 3
  How many drinks? 2
  How many chips? 4

		 Your total bill is $20

---------------- #a3. ----------------
Enter a three digit integer number: 452
Sum of digits in 452 is 11

---------------- #a4. ----------------
Enter temperature in Fahrenheit: 78
78F is 35C
Press any key to continue . . .
---------------------------------------------------------------*/