/*----------------------------------------------------------------------------
		Name:		Raymond Magdaleno
		Assignment:	8, Question 3
		Due Date:	1/30/2020

		Purpose:	Given a 3D array, find the total number of all,
					  medium, short sleeve, and blue shirts.
----------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

// Variables
int i, med, sSlv, blue, n2 = 2;
int a[3][3][2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };

// Displays output
void output()
{
	cout << "Total number of all shirts = " << i << endl;
	cout << "Total number of all Medium shirts = " << med << endl;
	cout << "Total of all Short Sleeve shirts = " << sSlv << endl;
	cout << "Total number of all Blue shirts = " << blue << endl;
}

int main()
{
	_asm
	{
		mov		i, 1;		// i = 1
		mov		med, 0;		// med = 0
		mov		sSlv, 0;	// sSlv = 0
		mov		blue, 0;	// blue = 0
		lea		edi, a;		// edi = a[][][]
	loopAll:
		cmp		i, 18;		// Compare i, 18;
		Jg		finish;		// i >= 18: finish
		mov		ebx, [edi];	// ebx = [edi]
		mov		eax, i;		// eax = i

	checkS_Slv:
		cdq;				// edx:eax = i
		idiv	n2;			// edx = edi % 2
		cmp		edx, 0;		// Compare edi % 2, 0
		Je		isS_Slv;	// edi % 2 == 0: isS_Slv

	checkBlue:
		cmp		i, 7;		// Compare i, 7
		Jge		maybeBlue;	// i >= 7: maybeBlue
		Jmp		checkM3;	// GOTO nextLoop()
	maybeBlue:
		cmp		i, 12;		// Compare i ,12
		Jle		isBlue;		// i <= 12: isBlue
		Jmp		checkM3;	// GOTO nextLoop

	isS_Slv:
		inc		sSlv;		// sSlv++
		Jmp		checkBlue;	// GOTO checkBlue
	isBlue:
		inc		blue;		// blue++

	checkM3:
		cmp		i, 3;		// Compare i, 3
		Jne		checkM4;	// i != 3: checkM4
		Jmp		isMedium;	// GOTO isMedium
	checkM4:
		cmp		i, 4;		// Compare i, 4
		Jne		checkM9;	// i != 4: checkM9
		Jmp		isMedium;	// GOTO isMedium
	checkM9:
		cmp		i, 9;		// Compare i, 9
		Jne		checkM10;	// i != 9: checkM10
		Jmp		isMedium;	// GOTO isMedium
	checkM10:
		cmp		i, 10;		// Compare i, 10
		Jne		checkM15;	// i != 10: checkM15
		Jmp		isMedium;	// GOTO isMedium
	checkM15:
		cmp		i, 15;		// Compare i, 15
		Jne		checkM16;	// i != 15: checkM16
		Jmp		isMedium;	// GOTO isMedium
	checkM16:
		cmp		i, 16;		// Compare i, 16
		Jne		nextLoop;	// i != 16: nextLoop
	isMedium:
		inc		med;		// med++

	nextLoop:
		inc		i;			// i++
		add		edi, 4;		// edi = edi + 4
		Jmp		loopAll;	// GOTO loopALL

	finish:
		dec		i;			// i--
		call	output;		// Call output()
	}
	system("pause");
	return 0;
}
/*--------------------------------Output--------------------------------------
Total number of all shirts = 18
Total number of all Medium shirts = 6
Total of all Short Sleeve shirts = 9
Total number of all Blue shirts = 6
Press any key to continue . . .
----------------------------------------------------------------------------*/