/*----------------------------------------------------------------------
Purpose:	Write an assem program to display information the AX register will hold if an interrupt occurred.
----------------------------------------------------------------------*/
#include <iostream>
using namespace std;

// Variables
short cBit, temp, ram, pri, drive, i = 0, reg = 0xFB86;

// Display base2 setup
void dispBase2()
{
	cout << "This is the content of AX at base 2: ";
}

// Display '0'
void disp0()
{
	cout << "0";
}
// Display '1'
void disp1()
{
	cout << "1";
}

// Display spacing
void dispSpace()
{
	cout << " ";
}

// Display RAM size
void dispRAM()
{
	cout << endl << endl;
	cout << "The size of RAM is " << ram << "K" << endl;
}

// Display # of drives
void dispFlop()
{
	cout << "The number of floppy drives are " << drive << endl;
}

// Display # of printers
void dispPrint()
{
	cout << "The number of installed printers are " << pri << endl;
}

// Display with adaptor
void isAdapt()
{
	cout << "Game adaptor is installed" << endl;
}
// Display without adaptor
void notAdapt()
{
	cout << "Game adaptor is not installed" << endl;
}

int main()
{
	_asm
	{
		call	dispBase2;		// Call dispBase2()
		mov		bx, reg;		// bx = 0xFB86
		mov		temp, bx;		// temp = 0xFB86
		mov		cBit, 1;		// cBit = 1
		shl 	cBit, 15;		// cBit << 15

	fLoop:
		cmp		i, 16;			// Compare i, 16
		Jge		findRAM;		// i >= 16: finish
		mov		bx, temp;		// bx = temp
		and cBit, bx;		// cBit = cBit & temp
	check0:
		cmp		cBit, 0;		// Compare cBit, 0
		Jne		is1;			// cBit != 0: is1
		call	disp0;			// call disp0()
		Jmp		checkSpace;		// GOTO checkSpace
	is1:
		call	disp1;			// Call disp1()

	checkSpace:
		mov		cx, 4;			// cx = 4
		mov		ax, i;			// ax = i
		cwd;					// dx:ax = i
		idiv	cx;				// dx = i % 4
		cmp		dx, 3;			// Compare i % 4, 3
		Jne		nextBit;		// i % 4 != 3: nextBit
		call	dispSpace;		// Call dispSpace()

	nextBit:
		shl		temp, 1;		// temp << 1
		mov		cBit, 1;		// cBit = 1
		shl		cBit, 15;		// bcBit << 15
		inc		i;				// i++
		Jmp		fLoop;			// GOTO fLoop

	findRAM:
		mov		bx, reg;		// bx = 0xFB86
		mov		cBit, 12;		// cBit = 12
		and cBit, bx;		// cBit = 12 & 0xFB86
		shr		cBit, 2;		// cBit = [Bit3][Bit2]
	checkRAM00:
		cmp		cBit, 0;		// Compare bits3&2, 0
		Jne		checkRAM01;		// bits3&2 != 0: checkRAM01
		mov		ram, 16;		// ram = 16
		jmp		displayRAM;		// GOTO displayRAM
	checkRAM01:
		cmp		cBit, 1;		// Compare bits3&2, 1
		Jne		checkRAM10;		// bits3&2 != 1: checkRAM10
		mov		ram, 32;		// ram = 32
		jmp		displayRAM;		// GOTO displayRAM
	checkRAM10:
		cmp		cBit, 2;		// Compare bits3&2, 2
		Jne		isRAM11;		// bits3&2 != 2: isRAM11
		mov		ram, 64;		// ram = 64
		jmp		displayRAM;		// GOTO displayRAM
	isRAM11:
		mov		ram, 128;		// ram = 128
	displayRAM:
		call	dispRAM;		// Call dispRAM()

	findFloppy:
		mov		cBit, 0x01C0;	// cBit = 0x01C0
		and cBit, bx;		// cBit =  0x01C0 & 0xFB86	
		shr		cBit, 6;		// cBit = [Bit8][Bit7][Bit6]
		mov		cx, cBit;		// cx = bits8,7,6
		inc		cx;				// cx = bits8,7,6 + 1
		mov		drive, cx;		// drive = bits8,7,6 + 1
		call	dispFlop;		// Call dispFlop()

	findPrint:
		mov		cBit, 0xE000;	// cBit = 0xE000
		and cBit, bx;		// cBit = 0xE000 & 0xFB86
		shr		cBit, 13;		// cBit = [Bit15][Bit14][Bit13]
		mov		cx, cBit;		// cx = bits15,14,13
		mov		pri, cx;		// pri = bits15,14,13
		call	dispPrint;		// Call dispPrint()

	findAdapt:
		mov		cBit, 0x1000;	// cBit = 0x1000
		and cBit, bx;		// cBit = 0x1000 & 0xFB86
		shr		cBit, 12;		// cBit = [Bit12]
	checkAdapt:
		cmp		cBit, 0;		// Compare cBit, 0
		Je		noAdapt;		// cBit == 0: noAdapt
		call	isAdapt;		// Call isAdapt()
		Jmp		finish;			// GOTO finish
	noAdapt:
		call	notAdapt;		// Call notAdapt()

	finish:
	}
	system("pause");
	return 0;
}
/*------------------------------Output----------------------------------
This is the content of AX at base 2: 1111 1011 1000 0110

The size of RAM is 32K
The number of floppy drives are 7
The number of installed printers are 7
Game adaptor is installed
Press any key to continue . . .
----------------------------------------------------------------------*/
