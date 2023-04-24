/*---------------------------------------------------------------
Purpose: Find the age and gender of the user.
---------------------------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

// Variables
string name;
char gender;
int age, cost;

// Displays menu
void displayMenu()
{
	cout << "-------- La Verne Private Club --------\n";
	cout << "Male                                   \n";
	cout << "     Children(age<13)...............$50\n";
	cout << "     Teenagers(13<=age<=19).........$70\n";
	cout << "     Adults(age>19)................$100\n";
	cout << "Female                                 \n";
	cout << "     Children(age<13)...............$40\n";
	cout << "     Teenagers(13<=age<=19).........$80\n";
	cout << "     Adults(age>19)................$120\n";
	cout << "                                       \n";
}

// Output
void displayCost()
{
	cout << "\t" << name << ", your membership is $" << cost << endl;
}

int main()
{
	displayMenu();
	// Inputs
	cout << "Please enter your name: ";
	cin >> name;
	cout << name << ", enter your age and gender(m/f): ";
	cin >> age >> gender;

	_asm
	{
		cmp		gender, 'f';	// Compare gender, f
		Jne		maybeMale;		// gender != f: maybeMale

	female:
		cmp		age, 13;		// Compare age, 13
		Jnl		notFChild;		// age != 13: notFChild

	isFChild:
		mov		cost, 40;		// cost = 40
		Jmp		finish;			// GOTO finish

	notFChild:
		cmp		age, 19;		// Compare age, 19
		Jng		isFTeen;		// age !> 19: isFTeen

	isFAdult:
		mov		cost, 100;		// cost = 100
		Jmp		finish;			// GOTO finish

	isFTeen:
		mov		cost, 70;		// cost = 70
		Jmp		finish;			// GOTO finish

	maybeMale:
		cmp		gender, 'F';	// Compare gender, F
		Je		female;			// gender == F: female

	male:
		cmp		age, 13;		// Compare age, 13
		Jnl		notMChild;		// age != 13: notMChild

	isMChild:
		mov		cost, 50;		// cost = 50
		Jmp		finish;			// GOTO finish

	notMChild:
		cmp		age, 19;		// Compare age, 19
		Jng		isMTeen;		// age !> 19: isMTeen

	isMAdult:
		mov		cost, 120;		// cost = 120
		Jmp		finish;			// GOTO finish

	isMTeen:
		mov		cost, 80;		// cost = 80

	finish:
		call	displayCost;	// Call displayCost()
	}

	system("pause");
	return 0;
}
/*------------------------------Output---------------------------
-------- La Verne Private Club --------
Male
	 Children(age<13)...............$50
	 Teenagers(13<=age<=19).........$70
	 Adults(age>19)................$100
Female
	 Children(age<13)...............$40
	 Teenagers(13<=age<=19).........$80
	 Adults(age>19)................$120

Please enter your name: Raimondo
Raimondo, enter your age and gender(m/f): 7 M
	Raimondo, your membership is $50
Press any key to continue . . .

-------- La Verne Private Club --------
Male
	 Children(age<13)...............$50
	 Teenagers(13<=age<=19).........$70
	 Adults(age>19)................$100
Female
	 Children(age<13)...............$40
	 Teenagers(13<=age<=19).........$80
	 Adults(age>19)................$120

Please enter your name: Raymond
Raymond, enter your age and gender(m/f): 15 m
	Raymond, your membership is $80
Press any key to continue . . .

-------- La Verne Private Club --------
Male
	 Children(age<13)...............$50
	 Teenagers(13<=age<=19).........$70
	 Adults(age>19)................$100
Female
	 Children(age<13)...............$40
	 Teenagers(13<=age<=19).........$80
	 Adults(age>19)................$120

Please enter your name: Ramon
Ramon, enter your age and gender(m/f): 27 M
	Ramon, your membership is $120
Press any key to continue . . .
---------------------------------------------------------------*/
