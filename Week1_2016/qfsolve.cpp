#include <cmath>
#include <iostream>
using namespace std;

/**
 * @brief Solves the given quadratic equation.
 *
 * This function, given real coefficients A, B, C to the equation
 * A*x*x + B*x + C = 0, returns the real part of a solution to the
 * equation thus defined. Where two real solutions exist, the one
 * closer to positive infinity is chosen.
 *
 * @param a the quadratic coefficient.
 * @param b the linear coefficient.
 * @param c the constant coefficient.
 *
 * @return the real part of a solution to the defined quadratic equation,
 *         as described.
 */

double qfsolve( double a, double b, double c)
{
	double determinant = b * b - 4 * a * c;
	if (determinant <= 0)
	{
		return (-1 * b / (2 * a));
	}

	else
	{
		double sol = (-b + sqrt(determinant)) / (2 * a);
		double sol2 = (-b - sqrt(determinant)) / (2 * a);

		return max(sol, sol2);
	}
}

int main ()
{
	cout << "a = 1, b = -1, c = -30 ==> x = " << qfsolve(1, -1, -30) << endl;
	cout << "a = 1, b = -10, c = 18 ==> x = " << qfsolve(1, -10, 18) << endl;
	cout << "a = 1, b = -7, c = 3 ==> x = " << qfsolve(1, -7, 3) << endl;
	cout << "a = 2, b = -1, c = 7 ==> x = " << qfsolve(2, -1, 7) << endl;
	cout << "a = 2, b = 1, c = -7 ==> x = " << qfsolve(2, 1, -7) << endl;
	return 0;

}