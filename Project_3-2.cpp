/*---------------------------------------------------------------
Purpose: Complete a 7-11 transaction: # of drinks & sandwiches, drink type, and sandwich size. Then calculate the bill.
---------------------------------------------------------------*/
#include <iostream>
using namespace std;

// Variables
int drinkNum, sandwNum, sandwSize, bill;
char drinkType;

void displayMenu()
{
	cout << "------- 7-11 Convenient Store -------\n";
	cout << "Drinks                               \n";
	cout << "  Soda(S)..........................$2\n";
	cout << "  Water(W).........................$1\n";
	cout << "  Beer(B)..........................$3\n";
	cout << "Sandwiches                           \n";
	cout << "  6 inches.........................$2\n";
	cout << "  10 inches........................$3\n";
	cout << "  12 inches........................$5\n";
	cout << "                                     \n";
}

// Inputs
void inputs()
{
	cout << "How many drinks? ";
	cin >> drinkNum;
	cout << "  What kind of drink(S=Soda, W=Water, B=Beer)? ";
	cin >> drinkType;
	tolower(drinkType);
	cout << "How many Sandwiches? ";
	cin >> sandwNum;
	cout << "  What size of sandwich(6/10/12 inches)? ";
	cin >> sandwSize;
}

// Display Output
void totBill()
{
	cout << "Your total bill = $" << bill << endl;
}

int main()
{
	_asm
	{
		call	displayMenu;	// Call dsiplayMenu()
		call	inputs;			// Call inputs()

		cmp		drinkType, 'S';	// Compare drinkType, 'S'
		Jne		notSoda;		// drinkType != 'S': notSoda

	soda:
		mov		ebx, 2;			// ebx = 2
		Jmp		drinkCalc;		// GOTO drinkCalc

	notSoda:
		cmp		drinkType, 'W';	// Compare drinkType, 'W'
		Jne		beer;			// drinkType != 'W': beer

	water:
		mov		ebx, 1;			// ebx = 1
		Jmp		drinkCalc;		// GOTO drinkCalc

	beer:
		mov		ebx, 3;			// ebx = 3

	drinkCalc:
		mov		eax, drinkNum;	// eax = drinkNum
		imul	ebx;			// edx:eax = drinkNum * ebx
		mov		bill, eax;		// bill = drinkNum * ebx

		cmp		sandwSize, 6;	// Compare sandwSize, 6
		Jne		notSixInch;		// sandwSize != 6: notSixInch

	sixInch:
		mov		ebx, 2;			// ebx = 2
		Jmp		sandwCalc;		// GOTO sandwCalc

	notSixInch:
		cmp		sandwSize, 10;	// Compare sandwSize, 10
		Jne		twelveInch;		// sandWsize != 10: twelveInch

	tenInch:
		mov		ebx, 3;			// ebx = 3
		Jmp		sandwCalc;		// GOTO sandwCalc

	twelveInch:
		mov		ebx, 5;			// ebx = 5

	sandwCalc:
		mov		eax, sandwNum;	// eax = sandwNum
		imul	ebx;			// sandwNum * ebx
		add		bill, eax;		// bill = drinkNum * ebx + sandwNum * ebx

		call	totBill;		// Call totBill()

	}

	system("pause");
	return 0;
}
/*------------------------------Output---------------------------
------- 7-11 Convenient Store -------
Drinks
  Soda(S)..........................$2
  Water(W).........................$1
  Beer(B)..........................$3
Sandwiches
  6 inches.........................$2
  10 inches........................$3
  12 inches........................$5

How many drinks? 2
	What kind of drink(S=Soda, W=Water, B=Beer)? S
How many Sandwiches? 3
	What size of sandwich(6/10/12 inches)? 6
Your total bill = $10
Press any key to continue . . .

How many drinks? 2
	What kind of drink(S=Soda, W=Water, B=Beer)? B
How many Sandwiches? 2
	What size of sandwich(6/10/12 inches)? 12
Your total bill = $16
Press any key to continue . . .
---------------------------------------------------------------*/
