#include <iostream>
using namespace std;

#include "Box.h"

int main()
{
	Box A;
	
	cout << "Surface of Box A: " << A.Surface() << endl;
	cout << A.Display_Quantity() << endl;
	
	Box B(2, 2, 2);
	cout << "Surface of Box B: " << B.Surface() << endl;
	cout << B.Display_Quantity() << endl;

	if (A.compare(B)) {
		cout << "B is smaller than A" << endl;
	}
	else {
		cout << "B is equal to or larger than A" << endl;
	}

	
	{                                                           //Oi agkules xrisimopoiountai gia na katadeixoun ti diafora sti posotita koutiwn entos kai ektos autou tou scope me klisi tou destructor. Den exupiretoun kati pio "xristiko" apo pleuras leitourgikotitas.
	Box B[5];                                                   //Dimiourgia array B me 5 koutia.
	
	cout << B[5].Display_Quantity() << endl;                    //Apodwsi stin othoni tis posotitas twn koutiwn pou exoun dimiourgithei mexri stigmis. Profanws edw 1 + 5 = 6.
	cout << B[3].Get_Height() << endl;                          //Apodwsi upsous stin othoni sumfwna me tin arxikopoiisi pou kanei o constructor. To 3o kouti opws kai ta upoloipa 4 autou tou array  exoun tis arxikopoiimenes times. (5).
	}

	cout << A.Display_Quantity() << endl;                       //Apodwsi stin othoni tis posotitas twn koutiwn pou exoun dimiourgithei mexri stigmis. Profanws edw 6-5=1 kathws kaleitai o destructor ektos tou scope tou Box B[5].

	Box C(A);                                                   //copy constructor: Desmeuei tin idia posotita mnimis prokeimenou na antigrapsei tis times tou A sto C. Den kataskeuasame apeutheias to kouti C alla to prosidiorisame antigrafwntas (copy) tis times tou A.
	cout << "COpy costr"<<C.Display_Quantity() << endl;
	cout << C.Get_Height() << endl;                             //Apodwsi upsous tou koutiou C stin othoni. paratiroume oti einai omoio me auto tou A (opws eixe allaxthei se 4).
	cout << C.Surface() << endl;                                //Ypologismos kai apodwsi stin othoni tou emvadou epifaneias tou koutiou C. Omoiws (254).


	//Classes and pointers

	
	Box *ptrBoxC = new Box;
	// Now try to access a member using member access operator
	cout << "Surface of Box C: " << ptrBoxC->Surface() << endl;
	cout <<"----"<< B.Display_Quantity() << endl;
	delete ptrBoxC;
	ptrBoxC = &A;
	cout << "Surface of Box A: " << ptrBoxC->Surface() << endl;
	cout << ptrBoxC->Display_Quantity() << endl;
	cout << B.Display_Quantity() << endl;
	cout << "---//---";
	if (ptrBoxC->compare(B)) {
		cout << "B is smaller than A" << endl;
	}
	else {
		cout << "B is equal to or larger than A" << endl;
	}
	system("PAUSE");
	return 0;
}
