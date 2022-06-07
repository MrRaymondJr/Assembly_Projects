/*-------------------------------------------------------------------------------
		Name:		Raymond Maagdaleno
		Assignmnet:	#1, Question 6
		Due Date:	Thurs. 1/9/2020

		Purpose: Calculate the perimeter and area of a rectangle and triangle
		         using user inputed values.
-------------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

  // Variables
int leng, wid, a, b, c, h;
int permR, permT, areaR, areaT;

int main()
{
	cout << "  _______________                     /\\     \n";
	cout << " |               |                   /| \\    \n";
	cout << " |               | Width          a / |h \\ b \n";
	cout << " |_______________|                 /__|___\\  \n";
	cout << "      Length                          c       \n";

	  // Input
	cout << "Enter the values of width and length of the rectangle: ";
	cin >> wid >> leng;
	cout << "Enter the values of a, b, c, and h of the triangle: ";
	cin >> a >> b >> c >> h;

	_asm
	{
		  // Rectangle: perimeter
		mov		eax, leng;	// eax = length
		add		eax, wid;	// eax = length + width
		add		eax, eax;	// eax = 2(length) + 2(width)
		mov		permR, eax;	// permR = 2(length) + 2(width)

		  // Rectangle: area
		mov		ebx, leng;	// ebx = length
		imul	wid;		// edx:ebx = lenth * width
		mov		areaR, ebx;	// areaR = length * width

		  // Tiangle: perimeter
		mov		ecx, a;		// ecx = a
		add		ecx, b;		// ecx = a + b
		add		ecx, c;		// ecx = a + b + c
		mov		permT, ecx;	// permT = a + b + c
		
		  // Tiangle: area
		mov		areaT, 1;		// !!! NEED TO DIVIDE !!!
	}

	  // Output 
	cout << "\t Rectangle: perimeter = " << permR << " area = " << areaR << endl;
	cout << "\t Triangle: perimeter = " << permT << " area = " << areaT << endl;

	system("pause");
	return 0;
}
/*----------------------------Output-----------------------------
 _______________                     /\
|               |                   /| \
|               | Width          a / |h \ b
|_______________|                 /__|___\
     Length                          c
Enter the values of width and length of the rectangle: 5 10
Enter the values of a, b, c, and h of the triangle: 7 6 10 5
	Rectangle: perimeter = 30 area = 10
	Triangle: perimeter = 23 area = 25
Press any key to continue . . .
---------------------------------------------------------------*/