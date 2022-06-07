/*---------------------------------------------------------------
		Name:		Raymond Magdaleno
		Assignment:	4 Question 3
		Due Date:	1/16/2020

		Purpose:	Read a number & determine whether it is
					  divisible by 3 or not.
---------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

// Variables
int num, digSum;

// Displays output
void divisible()
{
	cout << "  " << num << " is divisible by 3" << endl;
}

// Displays output
void notDivisible()
{
	cout << "  " << num << " is not divisible by 3" << endl;
}

// Displays total of digits
void totalOfDigits()
{
	cout << "  Total of digits is " << digSum << endl;
}

// Inputs
void inputs()
{
	cout << "Enter a three digit integer number: ";
	cin >> num;
}

int main()
{
	_asm
	{
		call	inputs;			// Call inputs()

		  // 100's place
		mov		eax, num;		// eax = num
		cdq;					// edx:eax = num
		mov		ebx, 100;		// ebx = 100
		idiv	ebx;			// eax = num / 100, edx = num % 100
		mov		digSum, eax;	// digSum = num / 100
		  // 10's place
		mov		eax, edx;		// eax = num % 100
		mov		ebx, 10
			cdq;					// edx:eax = num % 100
		idiv	ebx;			// eax = num % 100 / 10, edx = num % 100 % 10
		add		digSum, eax;	// digSum = 100's + 10's place
		  // 1' place
		add		digSum, edx;	// digSum = 100's + 10's + 1's place

		call	totalOfDigits;	// Call totalOfDigits()

		mov		eax, digSum;	// eax = digSum
		cdq;					// edx:eax = digSum
		mov		ebx, 3;			// ebx = 3
		idiv	ebx;			// eax = digSum / 3, edx = digSum % 3

		cmp		edx, 0;			// Compare digSum % 3, 0
		Jne		nDivis;			// digSum % 3 != 0: nDiv

	divis:
		call	divisible;		// Call divisible()
		Jmp		finish;			// GOTO finish

	nDivis:
		call	notDivisible;	// Call notDivisible()

	finish:
	}

	system("pause");
	return 0;
}
/*------------------------------Output---------------------------
Enter a three digit integer number: 125
  Total of digits is 8
  125 is not divisible by 3
Press any key to continue . . .

Enter a three digit integer number: 225
  Total of digits is 9
  225 is divisible by 3
Press any key to continue . . .
---------------------------------------------------------------*/