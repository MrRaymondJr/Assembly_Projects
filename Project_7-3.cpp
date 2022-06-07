/*------------------------------------------------------------------------
		Name:		Raymond Magdaleno
		Assignment:	7, Question 3
		Due Date:	1/21/2020

		Purpose:	Display the content of AX at base 2 and use Ax
					  register to determine at which floors the
					  elevator will stop.
------------------------------------------------------------------------*/
#include <iostream>
#include <ctime>
using namespace std;

// Variables
short bit, temp, pers, elv, i;
char p;

// Generate random number & convert it to char
void genRand()
{
	pers = rand() % 15 + 1;
	p = pers;
}

// Output on & text
void displayBi()
{
	cout << "AX = ";
}

void displayElv()
{
	cout << endl << "Elevator will stop at the following floors: ";
}

// Output current i
void defective()
{
	cout << i << " ";
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
// Output spacing
void displaySp()
{
	cout << " ";
}

int main()
{
	srand(time(0));			// Random based on time

	_asm
	{
		/* Generate & keep 10 integers */
	getRandInt:
		call	displayBi;	// Call displayBi()
		mov		elv, 0;		// elv = 0
		mov		i, 0;		// i = 0

	fLoop1:
		cmp		i, 10;		// Compare i, 10
		Jge		dispFloors;	// i >= 10: dispFloors
		call	genRand;	// Call getRand()
		mov		cx, 1;		// cx = 1
		mov		cl, p;		// cl = [1-15]
		shl		cx, cl;		// cx = 1 << [1-15]
		or elv, cx;	// elv = elv | 1 << [1-15]
		inc		i;			// i++
		Jmp	fLoop1;			// GOTO fLoop1 

		  /* Display AX */
	dispFloors:
		mov		bx, elv;	// bx = elv
		mov		temp, bx;	// temp = elv
		mov		i, 0;		// i = 0
		mov		bit, 1;		// bit = 1
		shl 	bit, 15;	// bit << 15

	fLoop2:
		cmp		i, 16;		// Compare i, 16
		Jge		findFloors;	// i >= 16: findFloors
		mov		bx, temp;	// bx = elv
		and bit, bx;	// bit = bit & elv

	checkZero:
		cmp		bit, 0;		// Compare bit, 0
		Jne		isOne;		// bit != 0: isOne
		call	display0;	// call display0()
		Jmp		checkSpace;	// GOTO checkSpace
	isOne:
		call	display1;	// Call display1()
	checkSpace:
		mov		cx, 4;		// cx = 4
		mov		ax, i;		// ax = i
		cwd;				// dx:ax = i
		idiv	cx;			// dx = i % 4
		cmp		dx, 3;		// Compare i % 4, 3
		Jne		nextBit1;	// i % 4 != 3: nextBit1
		call	displaySp;	// Call displaySp()

	nextBit1:
		shl		temp, 1;	// temp << 1
		mov		bit, 1;		// bit = 1
		shl		bit, 15;	// bcBit << 15
		inc		i;			// i++
		Jmp		fLoop2;		// GOTO fLoop2

		  /* Find floors stopped at */
	findFloors:
		call	displayElv;	// Call displayElv()
		mov		ax, elv;	// ax = elv
		mov		temp, ax;	// temp = elv
		mov		i, 1;		// i = 1
		mov		bit, 1;		// bit = 1

	fLoop3:
		cmp		i, 16;		// Compare i, 16
		Jg		finish;		// i > 16: finish
		mov		ax, temp;	// ax = elv
		and bit, ax;	// bit = bit & elv

	checkDefect:
		cmp		bit, 0;		// Compare bit, 0
		Je		nextBit2;	// bit == 0: nextBit2
		call	defective;	// Call defective()

	nextBit2:
		shr		temp, 1;	// temp >> 1
		mov		bit, 1;		// bit = 1
		inc		i;			// i++
		Jmp		fLoop3;		// GOTO fLoop3

	finish:
	}
	cout << endl;

	system("pause");
	return 0;
}
/*-------------------------------Output-----------------------------------
AX = 1010 1000 1010 1000
Elevator will stop at the followisng floors: 4 6 8 12 14 16
Press any key to continue . . ..
------------------------------------------------------------------------*/