/*-------------------------------------------------------------------------------
		Name:		Raymond Magdaleno
		Assignmnet:	Misc. Sample Projects
-------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

// Variables
int a = 5, b = 7, c = 10, d = 11, e = 8, h = 9;	// 1.
short sand, drink, chips, total;				// 2.
short digit, sum;								// 3.
short fahr, cels;								// 4.

/*------------------------------ Question 1 --------------------------------*/
void p1()
{
	cout << "Calculates the area. \n";
	cout << "        ^            \n";
	cout << "       /|\\          \n";
	cout << "      / | \\=7       \n";
	cout << "     /  |  \\        \n";
	cout << "    /=5 |   \\       \n";
	cout << "   /    |=4  \\      \n";
	cout << "  <_____|_____>=8    \n";
	cout << "   \\    |=9  /      \n";
	cout << "    \\=10|   /		  \n";
	cout << "     \\  |  /=11	  \n";
	cout << "      \\ | /		  \n";
	cout << "       \\|/		  \n";
	cout << "        v			  \n";
	cout << " area =(4*8)/2 + (9*)";


}

/*------------------------------ Question 2 --------------------------------*/
void p2()
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

/*------------------------------ Question 3 --------------------------------*/
void p3()
{
	// Input
	cout << "Enter a three digit integer number: ";
	cin >> digit;

	_asm
	{
		// Hundred's place
		mov		ax, digit;	// ax = digit
		cwd;				// dx:ax = digit
		mov		bx, 100;	// bx = 100;
		idiv	bx;			// ax = digit / 100, dx = digit % 100
		mov		sum, ax;	// sum = digit / 100
							// Ten's place
		mov		ax, dx;		// ax = digit % 100
		cwd;				// dx:ax = digit % 100
		mov		bx, 10;		// bx = 10
		idiv	bx;			// ax = digit % 100 / 10, dx = digit % 100 % 10
		add		sum, ax;	// sum = (digit/100)+(digit%100/10)
							// One's place
		add		sum, dx;	// sum = (digit/100)+(digit%100/10)+(digit%100%10)
	}

	// Display
	cout << "Sum of digits in " << digit << " is " << sum << endl;
}

/*------------------------------ Question 4 --------------------------------*/
void p4()
{
	// Input
	cout << "Enter temperature in Fahrenheit: ";
	cin >> fahr;

	_asm
	{
		mov		ax, fahr;	// aex = fahr
		mov		bx, 5;		// bx = 5
		mov		cx, 9;		// cx = 9
		sub		ax, 32;	// aex = fahr - 32
		imul	bx;		// aex = 5(fahr - 32)
		idiv	cx;		// aex = 5(fahr - 32) / 9
		mov		cels, ax;	// cels = 5(fahr - 32) / 9
	}

	// Display
	cout << fahr << "F is " << cels << "C" << endl;
}

int main()
{
	cout << "---------------- #1. ----------------" << endl;
	p1();
	cout << endl << "---------------- #2. ----------------" << endl;
	p2();
	cout << endl << "---------------- #3. ----------------" << endl;
	p3();
	cout << endl << "---------------- #4. ----------------" << endl;
	p4();

	system("pause");
	return 0;
}
/*----------------------------Output-----------------------------
---------------- #1. ----------------
Calculates the area.
		^
	   /|\
	  / | \=7
	 /  |  \
	/=5 |   \
   /    |=4  \
  <_____|_____>=8
   \    |=9  /
	\=10|   /
	 \  |  /=11
	  \ | /
	   \|/
		v
 area =(4*8)/2 + (9*)
---------------- #2. ----------------
-------K Store menu-------
  Sandwich...........$4
  Drink..............$2
  Chips..............$1

  How many sandwiches? 4
  How many drinks? 3
  How many chips? 1

		 Your total bill is $23

---------------- #3. ----------------
Enter a three digit integer number: 369
Sum of digits in 369 is 18

---------------- #4. ----------------
Enter temperature in Fahrenheit: 85
85F is 29C
Press any key to continue . . .
---------------------------------------------------------------*/