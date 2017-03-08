/**
 * @file debugging1.cpp
 * @author The CS2 TA Team <cs2tas@caltech.edu>
 * @date 2014-2015
 * @copyright This code is in the public domain.
 *
 * @brief An example of the utility of print statements in debugging.
 */

/**
 * A couple of observations: After every iteration of the while loop, the value of b gets integer
 * divided by 2 while the value of a gets doubled. This can be explained by the ' <<=1' and '>>=1'
 * which shifts 1 bit to the left and 1 bit to the right respectively. When a series of bits gets 
 * shifted to the left by 1, it is essentially adding a 0 to the end and thus multiplying the decimal
 * representation of the series of bits by 2. Likewise, shifting to the right would equate to integer division by 2.
 * Also note that x only increments by a when b is an odd number. This is due to the bitwise and (&). 
 * Because b is being compared to 1 whose decimal representation is 0....0001, whenever the last bit of
 * the binary representation of b is 1 (which is equivalent to b being an odd number in base 10), then 
 * (....1 & 0..001) will return 1, not 0 and thus evaluate what is 
 * inside the if condition by increasing x. Changing values of a and b to negative numbers will make a and b
 * very large positive integers because the declared type is unsigned. It appears the max. value a and b can
 * take on is a bit over 4 billion. If the values of a and b exceed this limit, the compiler will output a warning
 * saying 'large integer implicitly truncated' which will throw off calculations because only lower bits will 
 * be used to represent the variable. x is the product of a and b. The algorithm resembles that used in ancient Egypt
 * otherwise known as peasant multiplication. The multiplier is repeatedly halved (ignoring the remainder) while the 
 * multiplicand is repeatedly doubled. Only add the multiplicand when the last digit of the multiplier is even to get 
 * the final product.
 */

#include <iostream>

using namespace std;

/**
 * @brief Does a thing.
 *
 * Does a thing, I dunno, you tell me.
 */
int main(int argc, char ** argv)
{
    // Much of the following is intentionally undocumented.
    // Part of the assignment is to figure out what is going on.
    // You may need to look up some operators!
    unsigned int a = 174, b = 127, x = 0;

    // This construct is known as a 'while loop'.
    // The interior of the loop is run if, and while,
    // the given condition is true.
    // The program proceeds past the loop if, and when,
    // the given condition is found to be false just before any iteration
    // of the interior of the loop.
    while (b != 0)
    {
	cout << "b: " << b << "       a: " << a << "        x: " << x << endl; 
        // This construct is known as a conditional statement
        // ('if' statement).
        // The interior of the statement is run exactly once in its entirety
        // if the given condition is found to be true.
        // Note that 'true' is defined as nonzero,
        // and 'false' is defined as zero.
        if ((b & 1) != 0)
        {
            cout << "Adding " << a << " to " << x << endl;
            x += a;
        }
        a <<= 1;
        b >>= 1;
	cout << "b: " << b << "       a: " << a << "        x: " << x << endl; 
    }

    // Question for you now: so what is x anyway?
    // x is the product of a and b.
    return 0;
}
