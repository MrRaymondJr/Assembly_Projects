/*--------------------------------------------------------------------
		Name:		Raymond Magdaleno
		Assignment:	5 Question 5
		Due Date:	1/16/2020

		Purpose:	Practice addition with two random integers <100.
--------------------------------------------------------------------*/
#include <iostream>
#include <ctime>
using namespace std;

// Variables
char c;
int num1, num2, guess, cAns = 0, wAns = 0;

// Display intro
void intro()
{
	cout << "Let's practice addition" << endl;
}

// Display CORRECT
void correct()
{
	cout << "     CORRECT" << endl;
}

// Display WRONG
void wrong()
{
	cout << "     WRONG" << endl;
}

// Display # of right & wrong
void finish()
{
	cout << endl << "  Number of CORRECT answers = " << cAns << endl;
	cout << "  Number of WRONG answers = " << wAns << endl;
}

// Generate random num1 & num2
void genRand()
{
	num1 = rand() % 100;
	num2 = rand() % 100;
}

// Input guess
void addition()
{
	cout << "  " << num1 << " + " << num2 << "= ? ";
	cin >> guess;
}

// Input c
void cont()
{
	cout << "CONTINUE(y/n)? ";
	cin >> c;
}



int main()
{
	srand(time(0));		// Makes random based on time
	_asm
	{
		call	intro;		// Call intro()

	start:
		call	genRand;	// Call genRand()
		call	addition;	// Call addition()
		mov		eax, num1;	// eax = num1
		add		eax, num2;	// eax = num1 + num2
		cmp		guess, eax;	// Compare guess, eax
		Jne		inCorrect;	// guess != eax: inCorrect
		call	correct;	// Call correct()
		inc		cAns;		// cAns++
		Jmp		restart;	// GOTO restart

	inCorrect:
		call	wrong;		// Call wrong()
		inc		wAns;		// wAns()

	restart:
		call	cont;		// Call cont()
		cmp		c, 'y';		// Compare c, 'y'
		Je		start;		// c == 'y': start
		call	finish;		// Call finish()
	}
	system("pause");
	return 0;
}
/*------------------------------Output--------------------------------
Let's practice addition
  65 + 32= ? 97
	 CORRECT
  CONTINUE(y/n)? y
  45 + 61= ? 101
	 WRONG
  CONTINUE(y/n)? y
  76 + 44= ? 120
	 CORRECT
  CONTINUE(y/n)? n

  Number of CORRECT answers = 2
  Number of WRONG answers = 1
Press any key to continue . . .
--------------------------------------------------------------------*/