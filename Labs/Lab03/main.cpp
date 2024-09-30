#include <iostream>
#include <string>
#include "Demos.h"

using namespace std;

//#define STANDARD_IO
//#define STRINGS

int main (int argc, char *argv[]) {
#ifdef STANDARD_IO
	// cout -- The Standard Output Stream
	cout << "Hello from cout" << endl;
	// cerr -- The Standard Output Stream for errors
	cerr << "Hello from cerr" << endl;
	// cin  -- The Standard Input Stream
	int x;
	cout << "Write an int: ";
	cin >> x;
	cout << "You typed: " << x << endl;

	cout << "Give 2 int values and 1 double: ";
	// TODO: Write the code and print the values
	int a, b; double d;
	cin >> a >> b >> d;
	cout << "a: " << a << " | b: " << b << " | d: " << d << endl;
	
	cout << "Give text: ";
	// TODO: Get text from input and print it
	string text;
	cin >> text;
	cout << "T: " << text << endl;

	cout << "Write a line ::\n";
	char buf[256];
	cin.ignore();	// Used to skip the \n (Enter) pressed by the user in the previous input
	cin.getline(buf,256);
	cout << "You typed :: " << buf << endl;
	string line;
	cout << "Write a line again ::\n";
	getline(cin,line);
	cout << "You typed :: " << line << endl;
	system("PAUSE");
#elif defined STRINGS
	string_examples();
	system("PAUSE");
#else defined SIMPLE_FILE_EXAMPLES
	simpleFileWriteExample ();
	//simpleReadExample ("testAsciiFile.txt");
	//readWriteBinaryExample ();
	system("PAUSE");
#endif

	return 0;
}