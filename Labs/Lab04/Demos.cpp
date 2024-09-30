#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>

#include "Utils.h"

using namespace std;

void string_examples ( void ) {
	// For an extented set of examples with std::strings check this URL http://anaturb.net/C/string_exapm.htm
	char *line = "Some text";

	// Initialization 
	// Using a char *
    string s1 (line);
    cout << "s1  is: " << s1 << endl;

    // copy constructor
    string s2 (s1);
    cout << "s2  is: " << s2 << endl;
		
    // 1st arg - C++ string
    // 2nd arg - start position
    // 3rd arg - number of characters
    string s3 (s2,5,4); // copy word 'text' from s2
    cout << "s3  is: " << s3 << endl;

	// again using iterators
	// 1 - start iterator
    // 2 - end iterator
    string s4 (s2.begin()+5,s2.end());
    cout << "s4  is: " << s4 << endl;

	// We can add strings
	string s5 = s4 + " Some";
	cout << "s5  is: " << s5 << endl;

	// We can append to strings
	s5 += " And Some";
	cout << "s5  is: " << s5 << endl;
	// or by using append()
	s5.append(" And Again");
	cout << "s5  is: " << s5 << endl;

	// Iterate all characters
	string s6("Hello World");
	string::iterator it;
	cout << "s6 char-by-char: " << endl;
	for (it=s6.begin(); it!=s6.end(); ++it) {
		cout << *it << endl;
	}

	// Get the const char * from a string
	const char *buf = s6.c_str();	// or .data()
	cout << "buf is: " << buf << endl;

	// Compare
	if (s1.compare(s2) == 0) {
		cout << "s1 is equal to s2" << endl;
	}

	// Check if empty
	string s7;
	if (s7.empty())
		cout << "s7 is empty" << endl;

	// Find last occurence of sub string
	cout << "Location of last \"And\" in s5 (" << s5 << ") is :: " << s5.rfind("And") << endl;

	// Get the substring of a string
	cout << "Text from last \"And\" in s5 to the end is :: " << s5.substr(s5.rfind("And")) << endl;
}

int readInputFile (char *inputFile, vector<string> &vContainer) {
	ifstream inFStream (inputFile);
	if ( !inFStream.is_open() ){
		cout <<"Cannot open input file\n";
		return 0;
	}

	// Just a string to store read data
	string line;

	// A simple way to cnt file lines
	int lineCnt = 0;

	// this getline is not the same as the function member we mentioned earlier!

	while(getline(inFStream,line)) {
		lineCnt++;
	}
	cout << "File :: " << inputFile << " has " << lineCnt << " lines." << endl;
	if (lineCnt == 0) {
		cout << "Input file is empty!" << endl;
		return 0;
	}

	// Now lets rewind file back to 
	inFStream.clear();
	inFStream.seekg(0, ios::beg);

	// Lets Read the First Line -- If not what expected this is not a file we expect
	getline(inFStream,line);

	// C string comparison -- returns 0 when strings are identical (case sensitive)
	//if ( strcmp (line.c_str(),"NAMESLIST") != 0 ) {
	// stricmp is the case insensitive equivalent
	//if ( stricmp (line.c_str(),"NaMeSlIsT") != 0 ) {
	// C++ way
	if ( line.compare("NAMESLIST") != 0 ) {
		cout << "This is not a NamesList File!" << endl;
		return 0;
	}

	// Now since this is the file we expected lets put the Names in our Data Structure
	while(getline(inFStream,line)) {
		if (line.empty())	// Skip Empty Lines
			continue;

		vContainer.push_back(line);
	}

	return 1;
}