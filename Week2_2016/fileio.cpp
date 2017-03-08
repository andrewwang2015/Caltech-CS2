/**
 * @file fileio.cpp
 * @author The CS2 TA Team <<cs2tas@caltech.edu>>
 * @version 1.0
 * @date 2013-2015
 * @copyright This code is in the public domain.
 *
 * @brief A brief example of file input (implementation).
 */

#include <fstream>
#include <iostream>
#include <vector>
#include "fileio.h"
#include <string>
#include <stdlib.h>
using namespace std;

/**
 * @brief Reads the integers in file and fills nums with these integers.
 *
 * @param file: File containing integers, one per line.
 * @param nums: Vector to fill with the integers in file.
 *
 * Notice that the vector is passed by reference, so you should fill the vector
 * and not return anything from this function.
 */
void readFile(char const *file, std::vector<int> &nums)
{
    // TODO Write a function which takes a filename and a vector of integers as
    // arguments and fills the vector with integers from the specified file.
	string line;
	fstream myfile (file);
	if (myfile.is_open()){
		while (getline (myfile,line)){
			int b = atoi(line.c_str());
			nums.push_back (b);
		}
	}

	myfile.close();




}
