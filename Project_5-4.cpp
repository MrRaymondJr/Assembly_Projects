/*--------------------------------------------------------------------
Purpose: Find the average, max, and min of scores.
--------------------------------------------------------------------*/
#include <iostream>
using namespace std;

// Variables
int nStud = 0, scores = 0, sum = 0, ave = 0, maxN = 0, minN = 100;

// Inputs
void inputs()
{
	cout << "Please enter the number of students: ";
	cin >> nStud;
	cout << "Enter " << nStud << " scores: ";
}

// Gets next character
void nextScore()
{
	cin >> scores;
}

// Displays Output
void output()
{
	cout << "   Class average: " << ave << endl;
	cout << "   Maximum score: " << maxN << endl;
	cout << "   Minimum score: " << minN << endl;
}

int main()
{
	_asm
	{
		call	inputs;			// Call inputs()
		mov		ebx, 0;			// ebx = 0

	fLoop:
		cmp		nStud, ebx;		// Compare nStud, ebx
		Jle		calcAve;		// nStud <= ebx: calcAve
		inc		ebx;			// ebx++
		call	nextScore;		// Call nextScore()
		mov		eax, scores;	// eax = scores
		add		sum, eax;		// sum = sum + eax

	checkMax:
		mov		ecx, maxN;		// ecx = maxN
		cmp		ecx, scores;	// Compare ecx, scores
		Jg		checkMin;		// ecx >= scores: checkMin
		mov		ecx, scores;	// ecx = scores
		mov		maxN, ecx;		// maxN = ecx

	checkMin:
		mov		edx, minN;		// edx = minN
		cmp		edx, scores;	// Compare edx, scores
		Jl		fLoop;			// edx <= scores: fLoop
		mov		edx, scores;	// edx = scores
		mov		minN, edx;		// minN = edx
		Jmp		fLoop;			// GOTO fLoop

	calcAve:
		mov		eax, sum;		// eax = sum
		cdq;					// edx:eax = sum
		idiv	nStud;			// eax = sum / nStud
		mov		ave, eax;		// ave = sum / nStud
		call	output;			// Call output()
	}

	system("pause");
	return 0;
}
/*------------------------------Output--------------------------------
Please enter the number of students: 5
Enter 5 scores: 85 75 55 95 80
   Class average: 78
   Maximum score: 95
   Minimum score: 55
Press any key to continue . . .
--------------------------------------------------------------------*/
