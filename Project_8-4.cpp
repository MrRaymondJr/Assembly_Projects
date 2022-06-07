/*----------------------------------------------------------------------------
		Name:		Raymond Magdaleno
		Assignment:	8, Question 4
		Due Date:	1/30/2020

		Purpose:	Store random integers into array s, display the array,
					  sort the array, then display it again.
----------------------------------------------------------------------------*/
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

// Variables
int i, x, lp, n;
int s[7];

// Assigns random integer
void getRand()
{
	x = rand() % 100;
}

// Output display info
void dispArray()
{
	cout << "This is the content of array a: ";
}
// Display current s[i]
void dispX()
{
	cout << x << " ";
}
// Output newLine
void newLine()
{
	cout << "\n";
}

// Sort array s
void sortS()
{
	int n = sizeof(s) / sizeof(s[0]);
	sort(s, s + n);
}

int main()
{
	srand(time(0));
	_asm
	{
		mov		i, 0;		// i = 0
		mov		lp, 0;		// lp = 0
		lea		esi, s;		// esi = s[7]
	randLoop:
		cmp		i, 7;		// Compare i, 7
		Je		display;	// i == 7: display
		call	getRand;	// Call getRand()
		mov		eax, x;		// eax = x
		mov[esi], eax;	// [esi] = x
		inc		i;			// i++
		add		esi, 4;		// esi = esi + 4
		Jmp		randLoop;	// GOTO randLoop

	display:
		call	dispArray;	// Call dispArray()
		mov		i, 0;		// i = 0
		lea		esi, s;		// esi = s[7]
	dispLoop:
		cmp		i, 7;		// Compare i, 7
		Je		sortArray;	// i == 7: sortArray
		mov		eax, [esi];	// eax = [esi]
		mov		x, eax;		// x = eax
		call	dispX;		// call dispX()
		add		esi, 4;		// esi = esi + 4
		inc		i;			// i++
		Jmp		dispLoop;	// GOTO dispLoop

	sortArray:
		call	newLine;	// Call newLine()
		inc		lp;			// lp++
		cmp		lp, 2;		// Compare lp, 2
		Je		finish;		// lp == 2: finish
		call	sortS;		// Call sortS()
		Jmp		display;	// GOTO display

	finish:
	}
	system("pause");
	return 0;
}
/*--------------------------------Output--------------------------------------
This is the content of array a: 39 31 25 50 62 33 60
This is the content of array a: 25 31 33 39 50 60 62
Press any key to continue . . .
----------------------------------------------------------------------------*/