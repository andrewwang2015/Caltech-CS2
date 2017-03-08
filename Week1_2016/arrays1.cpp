/**
 * @file arrays1.cpp
 * @author The CS2 TA Team <cs2tas@caltech.edu>
 * @date 2014-2015
 * @copyright This code is in the public domain.
 *
 * @brief An array example.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

#define TEST_SIZE 60

using namespace std;

/**
 *@brief Finds the maximum value in an array
 *
 *@param arr the input array
 *@n the size of the array
 *
 *@return the max. value of the array
 */

int findMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

/**
 *@brief Finds the arithmetic mean of the values in an array
 *
 *@param arr the input array
 *@n the size of the array
 *
 *@return the mean of the array
 */

 double findMean(int arr[], int n)
 {
    double mean = 0;

    for (int i = 0; i < n; i++)
    {
        mean += arr[i] / ((double)n);


    }

    return mean;
 }

 /**
 *@brief Replaces values of array with elements in ascending order
 *
 *@param arr the input array
 *@n the size of the array
 *
 *@return void
 */

 void replaceWithAscending (int arr[], int n)
 {
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
 }


//
// TODO: put user functions here
//

/**
 * @brief Sets up and runs an array example.
 */
int main(int argc, char ** argv)
{

    /*-------- CHANGE NOTHING BELOW THIS LINE FOR PART 1 --------*/
    int test_values[TEST_SIZE];
    int real_size;

    // seed the PRNG
    srand(time(nullptr));

    // initialize the test array to garbage
    for (int i = 0; i < TEST_SIZE; i++)
    {
        test_values[i] = rand();
    }

    // determine a real size
    real_size = TEST_SIZE - (rand() % 20);

    // initialize the meaningful part of the test array to random numbers
    // all of which are less than one million
    for (int i = 0; i < real_size; i++)
    {
        test_values[i] = rand() % 1000000;
    }
    /*-------- CHANGE NOTHING ABOVE THIS LINE FOR PART 1 --------*/

    //
    // TODO: do your stuff here with the array `test_values`
    // of dynamic size `real_size`
    //
    cout << endl;
    cout << "Initially, this array is: " << endl;
    cout << "[";
    for (int i = 0; i < real_size; i++)
    {
        if (i == real_size - 1)
        {
            cout << test_values[i];
        }
        else
        {
        cout << test_values[i] << ", ";
        }
    }
    cout << "]" << endl << endl;;


    cout << "The max value in this array is " << findMax(test_values, real_size) << endl << endl;

    cout << fixed;    // Fixes the decimal point so output is not in scientific notation
    cout.precision(5);  // 5 numbers after the decimal point
    cout << "The arithmetic mean of this array is " << findMean(test_values, real_size) << endl << endl;
    cout << "After replacing the elements in the array with an ascending sequence we get..." << endl;
    replaceWithAscending(test_values, real_size);
    cout << "[";
    for (int i = 0; i < real_size; i++)
    {
        if (i == real_size - 1)
        {
            cout << test_values[i];
        }
        else
        {
        cout << test_values[i] << ", ";
        }
    }
    cout << "]" << endl;
    cout << endl;



}
