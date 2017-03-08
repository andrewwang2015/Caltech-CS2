/**
 * @file pointers4.cpp
 * @author The CS2 TA Team <cs2tas@caltech.edu>
 * @date 2015
 * @copyright This code is in the public domain.
 *
 * @brief Pointer-fu Exercise 4: Typecasting vs. address-of
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * @brief performs type castings
 */
int main(int argc, char *argv[])
{

    // To make 'b' point to 'a'and because b is already a pointer to an int and a is an int,
    // using the & to get the address of a and assigning that to b is valid. For getting the address
    // of the array, one has to track the variable c. It is initially declared as a void* meaning
    // it can be a pointer to any data type. That is why the (int *) is used to assign c to malloc...
    // In order to use c in assigning a value to b, c is already a pointer, so no need for the &. 
    // However, one has to be sure to include the (int *) because as previously said, c is initially of type
    // void * and must be converted to the type of b which is int *.  
    int a = 5, *b;
    void *c;

    // Now make `b` point to `a`.
    b = & a;


    /***** CHANGE NOTHING BELOW THIS LINE *****/
    cout << "The value pointed by `b` is " << *b;
    /***** CHANGE NOTHING ABOVE THIS LINE *****/

    // Allocate an array of 10 ints.
    c = (int *) malloc(10 * sizeof(int));

    // Get the address of the array.
    b = (int *) c;

    /***** CHANGE NOTHING BELOW THIS LINE *****/
    b[2] = 5;
    /***** CHANGE NOTHING ABOVE THIS LINE *****/
    
    return 0;
}
