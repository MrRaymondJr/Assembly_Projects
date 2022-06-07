/*--------------------------------------------------------------------
		Name:		Raymond Magdaleno
		Assignment:	5 Question 3
		Due Date:	1/14/2020

		Purpose:	Count the number of Yes/No votes in a string.
--------------------------------------------------------------------*/
#include <iostream>
using namespace std;

// Variables
char v;
int yVote = 0, nVote = 0;

// Inputs
void input()
{
	cout << "Enter a group of votes: \n";
}

// Gets next character
void nextVote()
{
	cin.get(v);
}

// Displays Output of Yes
void outputY()
{
	cout << "\tYES VOTES = " << yVote << " = ";
}

// Displays Output of No
void outputN()
{
	cout << endl << "\t NO VOTES = " << nVote << " = ";
}

// Output Stars
void star()
{
	cout << "* ";
}

int main()
{
	_asm
	{
		call	input;		// Call input()
		call	nextVote;	// Call nextVote()

	whLoop:
		cmp		v, '\n';	// Compare v, '\n'
		Je		outY;		// v == '\n': outY

	maybe_y:
		cmp		v, 'y';		// Compare v, 'y'
		Jne		maybeY;		// v != 'y': maybeY
		inc		yVote;		// yVote++
		Jmp		nextV;		// GOTO nextV

	maybeY:
		cmp		v, 'Y';		// Compare v, 'Y'
		Jne		maybe_n;	// v != 'Y': maybe_n
		inc		yVote;		// yVote++
		Jmp		nextV;		// GOTO nextV

	maybe_n:
		cmp		v, 'n';		// Compare v, 'n'
		Jne		maybeN;		// v != 'n': maybeN
		inc		nVote;		// nVote++
		Jmp		nextV;		// GOTO nextV

	maybeN:
		cmp		v, 'N';		// Compare v, 'N'
		Jne		nextV;		// v != 'N': nextV
		inc		nVote;		// nVote++

	nextV:
		call	nextVote;	// Call nextVote()
		Jmp		whLoop;		// GOTO whLoop

	outY:
		call	outputY;	// Call outputY()
		mov		eax, 0;		// eax = 0

	yStar:
		cmp		yVote, eax;	// Compare yVote, eax
		Jng		outN;		// yVote > eax: outN
		call	star;		// Call star()
		inc		eax;		// eax++
		Jmp		yStar;		// GOTO yStar

	outN:
		call	outputN;	// Call outputN()
		mov		eax, 0;		// eax = 0

	nStar:
		cmp		nVote, eax;	// Compare nVote, eax
		Jng		finish;		// nVote > eax: finish
		call	star;		// Call star()
		inc		eax;		// eax++
		Jmp		nStar;		// GOTO nStar

	finish:
	}
	cout << endl;

	system("pause");
	return 0;
}
/*------------------------------Output--------------------------------
Enter a group of votes:
yNNNYnyynN
YES VOTES = 4 = * * * *
 NO VOTES = 6 = * * * * * *
Press any key to continue . . .
--------------------------------------------------------------------*/