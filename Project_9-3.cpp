/*--------------------------------------------------------------
		Name:		Raymond Magdaleno
		Assignment:	9, Question 3
		Due Date:	1/30/2020

		Purpose:	Calculate a set amount of customer orders.
--------------------------------------------------------------*/
#include <iostream>
#include <iomanip>
using namespace std;

// Variables
char dT;
int	sZ, i, cNum;
float dNum, sNum, bill, s10 = 3.45, s12 = 5.25;
float dSoda = 2.25, dWater = 1.75, dJuice = 2.80;

// Display info & get # of customers
void numOfCust()
{
	cout << "---------------- 7-11 Convenient Store ----------------\n";
	cout << "Drinks                                                 \n";
	cout << "  Soda(S).........................................$2.25\n";
	cout << "  Water(W)........................................$1.75\n";
	cout << "  Juice(J)........................................$2.80\n";
	cout << "Sandwiches                                             \n";
	cout << "  10 inches.......................................$3.45\n";
	cout << "  12 inches.......................................$5.25\n";
	cout << "                                                       \n";
	cout << "Enter number of customers: ";
	cin >> cNum;
}

// Recieves user input
void custInfo()
{
	cout << "Customer " << i << ": " << endl;
	cout << "  How manny drinks? ";
	cin >> dNum;
	cout << "    What kind of drink(S=Soda, W=Water, J=Juice)? ";
	cin >> dT;
	toupper(dT);
	cout << "  How manny sandwiches? ";
	cin >> sNum;
	cout << "    What size of sandwich(10/12 inches)? ";
	cin >> sZ;
	toupper(sZ);
}

// Dsplays current customer bill
void totBill()
{
	cout << "\tYour total bill = " << bill << endl << endl;
}

int main()
{
	cout << fixed << showpoint << setprecision(2);
	_asm
	{
		mov		i, 1;			// i = 1
		call	numOfCust;		// Call numOfCust()

	custLoop:
		mov		ecx, cNum;		// ecx = cNum
		cmp		i, ecx;			// Compare i, cNum
		Jg		finish;			// i > cNum: finish
		call	custInfo;		// Call custInfo()
		fld		dNum;			// st: dNum

	drinkType:
		cmp		dT, 'S';		// Compare dT, 'S'
		Jne		notSoda;		// dT != 'S': notSoda
		fld		dSoda;			// st: dSoda | dNum
		Jmp		sandSize;		// GOTO sandSize
	notSoda:
		cmp		dT, 'W';		// Compare dT, 'W'
		Jne		isJuice;		// dT != 'W': isJuice
		fld		dWater;			// st: dWater | dNum
		Jmp		sandSize;		// GOTO sandSize
	isJuice:
		fld		dJuice;			// st: dJuice | dNum

	sandSize:
		fmul;					// st: dNum*dType
		fld		sNum;			// st: sNum | dNum*dType
		cmp		sZ, 10;			// Compare sZ, 10
		Jne		is12Inch;		// sZ != 10: is12Inch
		fld		s10;			// st: s10 | sNum | dNum*dType
		Jmp		calc;			// GOTO calc
	is12Inch:
		fld		s12;			// st: s12 | sNum | dNum*dType

	calc:
		fmul;					// st: sNum*sSize | dNum*dType
		fadd;					// st: dNum*dTypes+Num*sSize
		fstp	bill;			// bill = dNum * dTypes + Num * sSize
		call	totBill;		// Call totBill()
	nextLoop:
		inc		i;				// i++
		Jmp		custLoop;		// GOTO custLoop

	finish:
	}
	system("pause");
	return 0;
}
/*------------------------------Output--------------------------
---------------- 7-11 Convenient Store ----------------
Drinks
  Soda(S).........................................$2.25
  Water(W)........................................$1.75
  Juice(J)........................................$2.80
Sandwiches
  10 inches.......................................$3.45
  12 inches.......................................$5.25

Enter number of customers: 2
Customer 1:
  How manny drinks? 2
	What kind of drink(S=Soda, W=Water, J=Juice)? S
  How manny sandwiches? 3
	What size of sandwich(10/12 inches)? 10
	Your total bill = 14.85

Customer 2:
  How manny drinks? 3
	What kind of drink(S=Soda, W=Water, J=Juice)? J
  How manny sandwiches? 2
	What size of sandwich(10/12 inches)? 12
	Your total bill = 18.90

Press any key to continue . . .
--------------------------------------------------------------*/