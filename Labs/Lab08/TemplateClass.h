#ifndef _TEMPLATE_CLASS_H_
#define _TEMPLATE_CLASS_H_

#include <iostream>

using namespace std;

template <typename T, int N>
class Vector{
	T v[N];
public:
	Vector() {
		// Initialize Values to Zero
		for (int i=0; i<N; i++) 
			v[i] = 0;
	}
	
	//We can use this to access the array.
	// TODO: Make this safe!
	T& operator [](int i){
		if ( i < 0 || i >= N ) 
			i = 0;

		return v[i];
	}
	
	// TODO:: Implement the function so that it returns the maximum stored value
	T getMax(){
		T maxv = v[0];
		for(int i=1; i<N; i++)
			if(v[i]>maxv) maxv = v[i];
		return maxv;
	}
	
	void print() {
		std::cout<<"Array: ";
		for (int i=0; i<N; i++) {
			std::cout << v[i] << " ";
		}
		std::cout<< endl;
	}
};

#endif // _TEMPLATE_CLASS_H_
