/*------------------------------------------------------------------------
		Name:		Raymond Magdaleno
		Assignment:	7, Question 1
		Due Date:	1/21/2020

		Purpose:	Read a sentence, and output it with reverse casing.
------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

// Variables
char c;

// Input
void inputs()
{
	cout << "Enter a sentence: ";
}

// Spacing
void spacing()
{
	cout << "  ";
}

// Get next character
void getChar()
{
	cin.get(c);
}

// Output the character
void output()
{
	cout << c;
}

int main()
{
	_asm
	{
		call	inputs;		// Call inputs()
		call	getChar;	// Call getChar()
		call	spacing;	// Call spacing()

	wLoop:
		cmp		c, '\n';	// Compare c, '\n'
		Je		finish;		// c == '\n': finish

	checkLower:
		cmp		c, 90;		// Compare c, 90
		Jng		checkUpper;	// c !> 90: checkUpper
		sub		c, 32;		// c = c - 32
		Jmp		insert;		// GOTO insert

	checkUpper:
		cmp		c, 65;		// Compare c, 65
		Jng		insert;		// c !> 65: insert
		add		c, 32;		// c = c + 32
		Jmp		insert;		// GOTO insert

	insert:
		call	output;		// Call output()
		call	getChar;	// Call getChar()
		Jmp		wLoop;		// GOTO wLoop

	finish:
	}
	cout << endl;
	system("pause");
	return 0;
}
/*-------------------------------Output-----------------------------------
Enter a sentence: Today Is Tue
  tODAY iS tUE
Press any key to continue . . .
------------------------------------------------------------------------*/