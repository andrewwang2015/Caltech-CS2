/**
 * @file pointers3.cpp
 * @author The CS2 TA Team <cs2tas@caltech.edu>
 * @date 2015
 * @copyright This code is in the public domain.
 *
 * @brief Pointer-fu Exercise 3: "Entangled" pointers
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * @brief Set two pointers to the same memory and free them.
 */
int main(int argc, char *argv[])
{
    int *a, *b;

    // Allocate an array of 10 ints.
    a = (int *) malloc(10 * sizeof(int));

    // Now `b` points to the same array of ints.
    b = a;

    free(a);
    
    // Because a and b are pointing to the same location, by freeing a,
    // you are basically freeing b because the memory that was pointed to
    // by a and also b has been freed. Thus, 'free(b);' is redundant 
    // and can be ommitted.

    return 0;
}
