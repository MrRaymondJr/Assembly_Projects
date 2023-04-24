/*---------------------------------------------------------------
Purpose:	Determine wheter a read integer is ODD or EVEN.
---------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

// Variables
int num;


// Displays Even output
void displayEven()
{
	cout << "\t" << num << " is ODD" << endl;
}

// Displays Odd output
void displayOdd()
{
	cout << "\t" << num << " is EVEN" << endl;
}

int main()
{
	// Input	
	cout << "Enter a number: ";
	cin >> num;

	_asm
	{
		mov		eax, num;		// eax = num
		mov		ebx, 2;			// ebx = 2
		cdq;					// edx:eax = num
		idiv	ebx;			// eax = num / 2, edx = num % 2

		cmp		edx, 1;			// Compare edx, 1
		Jne		isOdd;			// edx != 1: isOdd

	isEven:
		call	displayEven;	// Call displayEven()
		Jmp		finish;			// GOTO finish

	isOdd:
		call	displayOdd;		// Call displayOdd()

	finish:
	}

	system("pause");
	return 0;
}
/*------------------------------Output---------------------------
Enter a number: 123
	123 is ODD
Press any key to continue . . .

Enter a number: 12
	12 is EVEN
Press any key to continue . . .

Enter a number: 335
	335 is ODD
Press any key to continue . . .
---------------------------------------------------------------*/
