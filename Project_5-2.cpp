/*--------------------------------------------------------------------
		Name:		Raymond Magdaleno
		Assignment:	5 Question 2
		Due Date:	1/14/2020

		Purpose:	Count the number of A's,B's,C's' and D's
					  from a user inputed 10 length string.
--------------------------------------------------------------------*/
#include <iostream>
using namespace std;

// Variables
char g;
int i, aCount = 0, bCount = 0, cCount = 0, dCount = 0;

// Inputs
void input()
{
	cout << "Enter 10 grades (A,B,C,D): ";
	cin.get(g);
}

// Gets next character
void nextGrade()
{
	cin.get(g);
}

// Displays Output
void output()
{
	cout << "Number of \"A's\" scores = " << aCount << endl;
	cout << "Number of \"B's\" scores = " << bCount << endl;
	cout << "Number of \"C's\" scores = " << cCount << endl;
	cout << "Number of \"D's\" scores = " << dCount << endl;
}

int main()
{
	_asm
	{
		call	input;		// call input()
		mov		i, 0;		// i = 0

	fLoop:
		inc		i;			// i++
		cmp		i, 10;		// Compare i, 10
		Je		done;		// i == 10: done

	test_a:
		cmp		g, 'a';		// Compare g, 'a'
		Jne		testA;		// g != 'a': testA
		inc		aCount;		// aCount++
		Jmp		nextCh;		// GOTO nextCh

	testA:
		cmp		g, 'A';		// Compare g, 'A'
		Jne		test_b;		// g != 'A': test_b
		inc		aCount;		// aCount++
		Jmp		nextCh;		// GOTO nextCh

	test_b:
		cmp		g, 'b';		// Compare g, 'b'
		Jne		testB;		// g != 'b': testB
		inc		bCount;		// bCount++
		Jmp		nextCh;		// GOTO nextCh


	testB:
		cmp		g, 'B';		// Compare g, 'B'
		Jne		test_c;		// g != 'B': test_c
		inc		bCount;		// bCount++
		Jmp		nextCh;		// GOTO nextCh

	test_c:
		cmp		g, 'c';		// Compare g, 'c'
		Jne		testC;		// G != 'c': testC
		inc		cCount;		// cCount++
		Jmp		nextCh;		// GOTO nextCh


	testC:
		cmp		g, 'C';		// Compare g, 'C'
		Jne		test_d;		// g != 'C': test_d
		inc		cCount;		// cCount++
		Jmp		nextCh;		// GOTO nextCh

	test_d:
		cmp		g, 'd';		// Compare g, 'd'
		Jne		testD;		// g != 'd': testD
		inc		dCount;		// dCount++
		Jmp		nextCh;		// GOTO nextCh


	testD:
		cmp		g, 'D';		// Compare g, 'D'
		Jne		nextCh;		// g != 'D': nextCh
		inc		dCount;		// dCount++

	nextCh:
		call	nextGrade;	// Call nextGrade()
		Jmp		fLoop;		// GOTO fLoop

	done:
		call	output;		// Call output()
	}

	system("pause");
	return 0;
}
/*------------------------------Output--------------------------------
Enter 10 grades (A,B,C,D): AbbBcCaA
Number of "A's" scores = 3
Number of "B's" scores = 3
Number of "C's" scores = 2
Number of "D's" scores = 0
Press any key to continue . . .
--------------------------------------------------------------------*/