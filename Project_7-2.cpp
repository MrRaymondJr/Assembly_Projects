/*------------------------------------------------------------------------
		Name:		Raymond Magdaleno
		Assignment:	7, Question 2
		Due Date:	1/21/2020

		Purpose:	a) Display Ax in binary
					b) Display # of sprinklers on
					c) Diplay each sprinkler # that is defective
------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

// Variables
short bi, temp;
short on = 0, i = 16, spr = 0x6A2F;

// Output text
void printBi()
{
	cout << "AX = ";
}

// Output '0'
void display0()
{
	cout << "0";
}
// Output '1'
void display1()
{
	cout << "1";
}

// Output on & text
void displayOn()
{
	cout << endl << on << " sprinklers are ON" << endl;
	cout << "Defective sprinkles are: ";
}

// Output current i
void defective()
{
	cout << i << " ";
}

int main()
{
	_asm
	{
		call	printBi;	// Call printBi()
		mov		ax, spr;	// ax = spr
		mov		temp, ax;	// temp = spr
		mov		bi, 1;		// bi = 1
		shl 	bi, 15;		// bi << 15

	fLoop:
		cmp		i, 0;		// Compare i, 0
		Jle		secondLoop;	// i <= 0: finish
		mov		ax, temp;	// ax = temp
		and bi, ax;		// bi = bi & temp

	checkOn:
		cmp		bi, 0;		// Compare bi, 0
		Je		isOff;		// bi == 0: isOff
		call	display1;	// Call display1()
		inc		on;			// on++
		Jmp		nextBit;	// GOTO nextBit

	isOff:
		call	display0;	// Call display0()

	nextBit:
		shl		temp, 1;	// temp << 1
		mov		bi, 1;		// cBit = 1
		shl		bi, 15;		// bcBit << 15
		dec		i;			// i++
		Jmp		fLoop;		// GOTO fLoop

	secondLoop:
		call	displayOn;	// Call displayOn()
		mov		i, 16;		// i = 16
		mov		ax, spr;	// ax = spr
		mov		temp, ax;	// temp = spr
		mov		bi, 1;		// bi = 1
		shl 	bi, 15;		// bi << 15

	fLoop2:
		cmp		i, 0;		// Compare i, 0
		Jle		finish;		// i <= 0: finish
		mov		ax, temp;	// ax = temp
		and bi, ax;		// cBit = cBit & temp

	checkDefect:
		cmp		bi, 0;		// Compare bi, 0
		Jne		nextBit2;	// bi != 0: nextBit2
		call	defective;	// Call defective

	nextBit2:
		shl		temp, 1;	// temp << 1
		mov		bi, 1;		// cBit = 1
		shl		bi, 15;		// bcBit << 15
		dec		i;			// i--
		Jmp		fLoop2;		// GOTO fLoop

	finish:
	}
	cout << endl;

	system("pause");
	return 0;
}
/*-------------------------------Output-----------------------------------
AX = 0110101000101111
9 sprinklers are ON
Defective sprinkles are: 16 13 11 9 8 7 5
Press any key to continue . . .
------------------------------------------------------------------------*/