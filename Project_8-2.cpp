/*----------------------------------------------------------------------------
		Name:		Raymond Magdaleno
		Assignment:	8, Question 2
		Due Date:	1/30/2020

		Purpose:	Compute & display the total # of all shirts, X-Large
					  shirts, and green shirts from data stored in a[4][4].
----------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

// Variables
int i, totA, totX, totG, n4 = 4;
int a[4][4] = { 10, 20, 30, 40,
				20, 10, 40, 30,
				5, 15, 20, 25,
				30, 25, 20, 15 };

// Displays output
void output()
{
	cout << "Total number of all shirts = " << totA << endl;
	cout << "Total number of X-Large shirts = " << totX << endl;
	cout << "Total number of Green shirts = " << totG << endl;
}

int main()
{
	_asm
	{
		mov		i, 1;		// i = 1
		mov		totA, 0;	// totA = 0
		mov		totX, 0;	// totX = 0
		mov		totG, 0;	// totG = 0
		lea		edi, a;		// edi = a[][]
	loopAll:
		cmp		i, 16;		// Compare i, 16;
		Jg		finish;		// i >= 16: finish
		mov		ebx, [edi];	// ebx = edi
		mov		eax, i;		// eax = i
		add		totA, ebx;	// totA = totA + ebx
	checkXL:
		cdq;				// edx:eax = i
		idiv	n4;			// edx = edi % 4
		cmp		edx, 0;		// Compare edi % 4, 0
		Je		isXL;		// edi % 4 == 0: isXL
	checkGreen:
		cmp		i, 5;		// Compare i, 5
		Jge		maybeGreen;	// i >= 5: maybeGreen
		Jmp		nextLoop;	// GOTO nextLoop()
	maybeGreen:
		cmp		i, 8;		// Compare i ,8
		Jle		isGreen;	// i <= 8: isGreen
		Jmp		nextLoop;	// GOTO nextLoop
	isXL:
		add		totX, ebx;	// totX = totX + ebx
		Jmp		checkGreen;	// GOTO checkGreen
	isGreen:
		add		totG, ebx;	// totG = totG + ebx
	nextLoop:
		inc		i;			// i++
		add		edi, 4;		// edi = edi + 4
		Jmp		loopAll;	// GOTO loopALL

	finish:
		call	output;		// Call output()
	}
	system("pause");
	return 0;
}
/*--------------------------------Output--------------------------------------
Total number of all shirts = 355
Total number of X-Large shirts = 110
Total number of Green shirts = 100
Press any key to continue . . .
----------------------------------------------------------------------------*/