/*----------------------------------------------------------------------
Purpose: Display the total, max, and min data in array a.
----------------------------------------------------------------------*/
#include <iostream>
using namespace std;

// Variables
int a[7] = { 33, 66, 11, 17, 20, 25, 10 };
int i = 0, x = 0, tot = 0, maxN = 0, minN = 100;

// Displays output
void output()
{
	cout << "The total of data in array a: " << tot << endl;
	cout << "The maximum data in array a: " << maxN << endl;
	cout << "The minimum data in array a: " << minN << endl;
}

int main()
{
	_asm
	{
		lea		ebx, a;		// ebx = a[]

	fLoop:
		cmp		i, 7;		// Compare i, 7
		Je		finish;		// i == 7: finish
		mov		ecx, [ebx];	// ecx = ebx[#]
		mov		x, ecx;		// x = ebx[#]
	checkMax:
		cmp		ecx, maxN;	// Compare ebx[#], max
		Jng		checkMin;	// ebx[#] !> max: checkMin
		mov		maxN, ecx;	// max = ebx[#]
	checkMin:
		cmp		ecx, minN;	// Compare ebx[#], min
		Jnl		nextLoop;	// ebx[#] !< min: nextLoop
		mov		minN, ecx;	// min = ebx[#]
	nextLoop:
		add		ebx, 4;		// ebx = ebx[#] + 4
		inc		i;			// i++
		add		tot, ecx;	// tot = tot + ebx[#]
		Jmp		fLoop;		// GOTO fLoop

	finish:
		call	output;		// Call output()
	}
	system("pause");
	return 0;
}
/*---------------------------------Output-------------------------------
The total of data in array a: 182
The maximum data in array a: 66
The minimum data in array a: 10
Press any key to continue . . .
----------------------------------------------------------------------*/
