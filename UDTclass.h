#pragma once
#pragma once
/*

Thaine Koen
12/16/2022
Header for User Defined Template class
*/
#ifndef deletePointers_H
#define deletePointers_H
#include <iostream>
#include <fstream>

using namespace std;


	template <typename T>
	inline void deletePointers(T*& pointers) {	//delete chosen pointer for the class object and set to null
		if (pointers) {
			delete pointers;
			pointers = 0;
		}
	};
#endif