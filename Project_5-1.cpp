/*--------------------------------------------------------------------
		Name:		Raymond Magdaleno
		Assignment:	5 Question 1
		Due Date:	1/16/2020

		Purpose:	Find the cost of a Fitness membership
--------------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

// Variables
string name;
int  g, age, cost;
char gen, c;

// Input name & gen
void nameAndGen()
{
	cout << "Enter your name and gender: ";
	cin >> name >> gen;
}

// Input age (Mr.)
void mrAge()
{
	cout << "Mr. " << name << ", how old are you? ";
	cin >> age;
}

// Input age (Ms.)
void msAge()
{
	cout << "Ms. " << name << ", how old are you? ";
	cin >> age;
}

// Input cont
void cont()
{
	cout << endl << "CONTINUE(y/n)? ";
	cin >> c;
	cout << endl;
}

// Output cost (Mr.)
void mrCost()
{
	cout << "  Mr. " << name << " your membership is $" << cost << endl;
}

// Output cost (Mr.)
void msCost()
{
	cout << "  Ms. " << name << " your membership is $" << cost << endl;
}

// Displays menu
void displayMenu()
{
	cout << "----------- Fitness -----------\n";
	cout << "Adult                              \n";
	cout << "  Male.........................$150\n";
	cout << "  Female.......................$100\n";
	cout << "Teenagers                          \n";
	cout << "  Male.........................$170\n";
	cout << "  Female.......................$300\n";
	cout << "                                   \n";

}

int main()
{
	_asm
	{
		call	displayMenu;	// Call displayMenu()

	start:
		call	nameAndGen;		// Call nameAndGen()

		cmp		gen, 'm';		// Compare gen, 'm'
		Jne		maybeM;			// gen != 'm': maybeM

	isM:
		call	mrAge;			// Call mrAge()
		mov		g, 0;			// g = 0
		Jmp		beginCost;		// GOTO beginCost

	maybeM:
		cmp		gen, 'M';		// Compare gen, 'M'
		Je		isM;			// gen == 'M': isM

	isF:
		mov		g, 1;			// g = 1
		call	msAge;			// Call msAge()

	beginCost:
		cmp		g, 0;			// Compare g, 0
		Jne		female;			// g != 0: female

	male:
		cmp		age, 19;		// Compare age, 19
		Jng		mTeen;			// age !> 19: mTeen

	mAdult:
		mov		cost, 150;		// cost = 150
		call	mrCost;			// call mrCost()
		Jmp		restart;		// GOTO restart

	mTeen:
		mov		cost, 170;		// cost = 170
		call	mrCost;			// call mrCost()
		Jmp		restart;		// GOTO restart

	female:
		cmp		age, 19;		// Compare age, 19
		Jng		fTeen;			// age !> 19: fTeen

	fAdult:
		mov		cost, 100;		// cost = 100
		call	msCost;			// Call msCost()
		Jmp		restart;		// GOTO restart

	fTeen:
		mov		cost, 300;		// cost = 300
		call	msCost;			// Call msCost()

	restart:
		call	cont;			// Call cont()
		cmp		c, 'y';			// Compare c, 'y'
		Je		start;			// c == 'y': start
	}
	system("pause");
	return 0;
}
/*------------------------------Output--------------------------------
----------- Fitness -----------
Adult
  Male.........................$150
  Female.......................$100
Teenagers
  Male.........................$170
  Female.......................$300

Enter your name and gender: John m
Mr. John, how old are you? 27
  Mr. John your membership is $150

CONTINUE(y/n)? y

Enter your name and gender: Mary F
Ms. Mary, how old are you? 15
  Ms. Mary your membership is $300

CONTINUE(y/n)? n

Press any key to continue . . .
--------------------------------------------------------------------*/