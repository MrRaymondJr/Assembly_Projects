/*----------------------------------------------------------------------
		Name:		Raymond Magdaleno
		Assignment:	6 Question 2
		Due Date:	1/23/2020

		Purpose:	Determine whether user inputed integers are either
					  even or odd without division.
----------------------------------------------------------------------*/
#include <iostream>
using namespace std;

// Variables
short loop, num;

// Input number of loops
void numLoops()
{
	cout << "How many numbers would you like to try: ";
	cin >> loop;
}

// Input integer number
void intNum()
{
	cout << "  Enter an integer number: ";
	cin >> num;
}

// Outputs num is Odd
void isOdd()
{
	cout << "\t" << num << " is ODD" << endl;
}
// Output num is Even
void isEven()
{
	cout << "\t" << num << " is EVEN" << endl;
}

int main()
{
	_asm
	{
		call  numLoops;		// Call numLoops()
		mov		bx, 0;		// bx = 0

	fLoop:
		cmp		bx, loop;	// Compare bx, loop
		Jge		finish;		// bx >= loop: finish
		call	intNum;		// Call intNum()
		mov		ax, num;	// ax = num
		and ax, 0x0001;	// ax = ax & 0x0001
	checkOdd:
		cmp		ax, 0;		// Compare ax, 0
		Je		numEven;	// ax == 0: numEven
		call	isOdd;		// Call isOdd()
		Jmp		nextLoop;	// GOTO nextLoop
	numEven:
		call	isEven;		// Call isEven()

	nextLoop:
		inc		bx;			// bx++
		Jmp		fLoop;		// GOTO fLoop

	finish:
	}
	system("pause");
	return 0;
}
/*------------------------------Output----------------------------------
How many numbers would you like to try: 4
  Enter an integer number: 124
	124 is EVEN
  Enter an integer number: 37
	37 is ODD
  Enter an integer number: 3456
	3456 is EVEN
  Enter an integer number: 555
	555 is ODD
Press any key to continue . . .
----------------------------------------------------------------------*/