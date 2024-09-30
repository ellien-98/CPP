#include <iostream>
using namespace std;

#include "Box.h"

//Class Functios
double Box::Volume()
{
	return height * width*length;                          //sunithizetai i metavlites na einai private kai oi sunartiseis public, polla omws exartwntai apo ti leitourgikotita pou epithumoume.
}

double Box::Surface()                                         //gia ton upologismo tou emvadou epifaneias
{
	return 2 * height*width + 2 * height*length + 2 * width*length;
}


int Box::Display_Quantity()                                  //gia apodwsi stin othoni tis posotitas twn koutiwn pou dimiourgithikan
{
	return Quantity;
}

bool Box::compare(Box &x) {
	cout << "compare" << this->Display_Quantity() << endl;
	return this->Volume() > x.Volume();
}

//Constructors	
//Contructor 1
Box::Box()                                                   //constructor: einai function alla DEN exei tupo (px void), exei idio setup me mia sunartisi kai panomoiotupo onoma me to struct/class
{                                                       //Einai upeuthunos gia tin arxikopoiisi twn koutiwn prokeimenou na min gtafw kathe fora A[123].height = ...  px gia array me 200 idia koutia -> Box A[200]
	height = 5;
	width = 7;
	length = 9;
	Quantity++;                                         //auxanei ti posotita kata ena me ti dimiourgia kathe koutiou. prepei na arxikopoiithei me sugkekrimeno trop (redeclare panw apo ti main)
	cout << "Constructor 2 called. Quantity: " << Quantity << endl;
}

//Contructor 2 - passing values
Box::Box(double l, double w, double h) {
	length = l;
	width = w;
	height = h;
	Quantity++;
	cout << "Constructor 1 called. Quantity: " << Quantity << endl;
}

//Contructor 3 - initialization list
/*Box::Box(double l = 2.0, double w = 2.0, double h = 2.0): length(l), width(w), height(h) // directly initialize our member variables
{
cout << "Constructor with Initialization list called." << endl;
// No need for assignment here
Quantity++;
}*/

//CopyContructor - initialization list
Box::Box(Box & or1) : length(or1.length), width(or1.width), height(or1.height) // directly initialize our member variables
{
	cout << "CopyConstructor with Initialization list called." << endl;
	// No need for assignment here
	Quantity++;
}



Box::~Box()                                                  //destructor. Opws o constructor, einai default gia metavlites xamilou epipedou kai "katharizei" ti mnimi afou autes katastrafoun ektos tou scope pou xrisimopoiountai.
{                                                       //Edw dilwnetai sugkekrimena gia tin katastrofi tis metavlitis Quantity pou desmeuei dunamika ti mnimi opote kai diatirei ti timi tis, an den trexei o destructor. Omoios orismos me constructor alla proigeitai i tilda.
	Quantity--;                                         //O constructor auxanei kata 1 ti posotita me dimiourgia Box, o destructor ti meiwnei antistoixa ektos scope.
	cout << "Destructor. Quantity: " << Quantity << endl;
}


int Box::Quantity = 0;                                          //redeclare gia ti xrisi tis static int Quantity. Aparaitito apo to C++ std.

