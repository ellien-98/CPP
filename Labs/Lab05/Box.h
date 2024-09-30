#include <iostream>
using namespace std;

class/*struct*/ Box                                              //keyword: struct/class -> to Box sumperiferetai san variable type px Box A opws int A; 
{
private:                                                     //keyword for access specifier. Ta private, den allazoun times sti main me xrisi dot operator, para mono mesw newn sunartiseewn (get/set)
	double height, width, length;                            //dunati i arxikopoiisi sti c++ 11 alla einai dokimo na min arxikopoiountai gia tin apofugi lathwn sti sunexeia. Ws private einai orates apo tis sunartiseis autou tou scope alla oxi apeutheias apo ti main.
	static int Quantity;                                     //static metavliti pou prosthetei 1 sti posotita kathe fora pou dimiourgeitai ena neo kouti (counter)

public:                                                      //an den xrisimopoiisw access specifiers uponoeitai to public gia struct kai private gia class. Diafora metaxu struct/class.

															 //Getters-Setters
	double Get_Height()                                     //gia apodwsi stin othoni tou upsous efoson ws private den einai dunato me cout << A.height gia Box A
	{
		return height;
	}
	void Change_Height(double x)                            //gia tin allagi tis timis tou upsous efoson ws private den einai dunati me  A.height = 10 gia Box A
	{
		height = x;
	}
	double Get_Width()
	{
		return width;
	}
	void Change_Width(double x)
	{
		width = x;
	}
	double Get_Length()
	{
		return length;
	}

	void Change_Length(double x)
	{
		length = x;
	}

	//Class Functios
	double Volume();

	double Surface();

	int Display_Quantity();

	bool compare(Box &x);

	//Constructors	
	//Contructor 1
	Box();

	//Contructor 2 - passing values
	Box(double l, double w, double h);
	
	//CopyContructor - initialization list
	Box(Box & or1);

	~Box();
};

