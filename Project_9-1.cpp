/*--------------------------------------------------------------
		Name:		Raymond Magdaleno
		Assignment:	9, Question 1
		Due Date:	1/30/2020

		Purpose:	Find the area/perimeter/surface area/volume
					  of a triangle, rectangle, and cylinder.
--------------------------------------------------------------*/
#include <iostream>
#include <iomanip>
using namespace std;

// Variables
float a, b, c, h, wid, leng, hgt, r, n2 = 2, pi = 3.14;
float triA, triP, recA, recP, cylSA, cylV;

// Recieves user input
void inputs()
{
	cout << "Enter the values of a, b, c, and h for the triangle: ";
	cin >> a >> b >> c >> h;
	cout << "Enter the length and width of the the rectangle: ";
	cin >> leng >> wid;
	cout << "Enter the radius and the height of the cylinder: ";
	cin >> r >> hgt;
}

// Displays output
void dispTri()
{
	cout << "Triangle" << endl;
	cout << "\tArea.............................." << triA << endl;
	cout << "\tPerimeter........................." << triP << endl;
}
void dispRec()
{
	cout << "Rectangle" << endl;
	cout << "\tArea.............................." << recA << endl;
	cout << "\tPerimeter........................." << recP << endl;
}
void dispCyl()
{
	cout << "Cylinder" << endl;
	cout << "\tSurface Area......................" << cylSA << endl;
	cout << "\tVolume............................" << cylV << endl;
}

int main()
{
	cout << fixed << showpoint << setprecision(2);
	_asm
	{
		call	inputs;		// Call inputs()

	triangleArea:
		fld		h;			// st: h
		fld		c;			// st: c | h
		fmul;				// st: h*c
		fld		n2;			// st: 2 | h*c
		fdiv;				// st: h*c/2
		fstp	triA;		// triA = h * c / 2
	trianglePerim:
		fld		a;			// st: a
		fld		b;			// st: b | a
		fadd;				// st: a+b
		fld		c;			// st: c | a+b
		fadd;				// st: a+b+c
		fstp	triP;		// triP = a + b + c
		call	dispTri;	// Call dispTri()

	rectangleArea:
		fld		wid;		// st: wid
		fld		leng;		// st: leng | wid
		fmul;				// st: wid*leng
		fstp	recA;		// recA = wid * leng
	rectanglePerim:
		fld		n2;			// st: 2
		fld		leng;		// st: leng | 2
		fmul;				// st: 2*leng
		fld		n2;			// st: 2 | 2*leng
		fld		wid;		// st: wid | 2 | 2*leng
		fmul;				// st: 2*wid | 2*leng
		fadd;				// st+ 2*leng+2*wid
		fstp	recP;		// recP = 2 * leng + 2 * wid
		call	dispRec;	// Call dispRec()

	cylinderSA:
		fld		n2;			// st: 2
		fld		pi;			// st: pi | 2
		fmul;				// st: 2*pi
		fld		r;			// st: r | 2*pi
		fmul;				// st: 2*pi*r
		fld		r;			// st: r | 2*pi*r
		fmul;				// st: 2*pi*r*r
		fld		n2;			// st: 2 | 2*pi*r*r
		fld		pi;			// st: pi | 2 | 2*pi*r*r
		fmul;				// st: 2*pi | 2*pi*r*r
		fld		r;			// st: r | 2*pi | 2*pi*r*r
		fmul;				// st: 2*pi*r | 2*pi*r*r
		fld		hgt;		// st: hgt | 2*pi*r | 2*pi*r*r
		fmul;				// st: 2*pi*r*hgt | 2*pi*r*r
		fadd;				// st: 2*pi*r*r+2*pi*r*hgt
		fstp	cylSA;		// cylSA = 2*pi*r^2 + 2*pi*r*hgt
	cylinderVol:
		fld		pi;			// st: pi
		fld		r;			// st: r | pi
		fmul;				// st: pi*r
		fld		r;			// st: r | pi*r
		fmul;				// st: pi*r*r
		fld		hgt;		// st: hgt | pi*r*r
		fmul;				// st: pi*r*r*hgt
		fstp	cylV;		// cylV = pi * r^2 * hgt
		call	dispCyl;	// Call dispCyl()
	}
	system("pause");
	return 0;
}
/*------------------------------Output--------------------------
Enter the values of a, b, c, and h for the triangle: 4.3 6.1 9.5 10.7
Enter the length and width of the the rectangle: 15.1 10.6
Enter the radius and the height of the cylinder: 5.9 11.5
Triangle
	Area..............................50.83
	Perimeter.........................19.90
Rectangle
	Area..............................160.06
	Perimeter.........................51.40
Cylinder
	Surface Area......................644.70
	Volume............................1256.99
Press any key to continue . . .
--------------------------------------------------------------*/