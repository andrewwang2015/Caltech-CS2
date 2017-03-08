/**
 * @file test_solver.cpp
 * @author Ellen Price <<eprice@caltech.edu>>
 * @version 1.0
 * @date 2013-2014
 * @copyright see License section
 *
 * @brief Simple test suite for Solver.
 *
 * @section License
 * Copyright (c) 2013-2014 California Institute of Technology.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following disclaimer
 *   in the documentation and/or other materials provided with the
 *   distribution.
 * * Neither the name of the  nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the California Institute of Technology.
 *
 */

#include "Solver.hpp"
#include <cstdio>

using namespace Solver;
using namespace std;
#include <iostream>

double f (double x)
{
	return x * x - 4 * x - 4;
}

double f_der (double x)
{
	return 2*x - 4;
}

double f1 (double x)
{
	return x*x - 3*x - 4;
}

double f1_der (double x)
{
	return 2 * x - 3;
}

double f2(double x)
{
	return x*x*x*x*x - 4*x + 4;
}

double f2_der (double x)
{
	return 5 * x * x * x * x - 4;
}

double f3(double x)
{
	return 2*x*x*x + 5*x*x - 4*x - 3;
}

double f3_der (double x)
{
	return 6 * x * x + 10 * x - 4;
}

double f4(double x)
{
	return 6*x*x*x*x*x*x + .5*x*x - .3*x - 3;
}

double f4_der (double x)
{
	return 36 * x * x * x * x * x + x - 0.3;
}

double f5(double x)
{
	return x*x*x*x*x - 10 * x * x * x + 9*x;
}

double f5_der(double x)
{
	return 5*x*x*x*x - 30 * x * x + 9;
}

int main()
{
	
	double root = bisection (&f, -3.0, 3.0);
	double root1 = bisection (&f1, 2.0 , 5.0);
	double root2 = bisection (&f2, -5.0, 5.0);
	double root3 = bisection (&f3, 0.0, 5.0);
	double root4 = bisection (&f4, 0.0, 3.0);
	double root5 = bisection (&f5, -5.0, -2.0);


	double root_NR = newton_raphson (&f, &f_der, -4.0);
	double root1_NR = newton_raphson (&f1, &f1_der, 10.0);
	double root2_NR = newton_raphson (&f2, &f2_der, -3.0);
	double root3_NR = newton_raphson (&f3, &f3_der, 3.0);
	double root4_NR = newton_raphson (&f4, &f4_der, 5.0);
	double root5_NR = newton_raphson (&f5,&f5_der, - 10.0);
	cout << endl;
	cout << "f(x) = x^2 - 4x - 4  |  Bounds: -3.0 , 3.0   |   Expected value: -0.828427   |   Bisection: " << root  << 
	"     |    Newton-Raphson: " << root_NR << endl << endl;

	cout << "f(x) = x^2 - 3x - 4  |  Bounds:  2.0 , 5.0   |   Expected value: 4   |   Bisection: " << root1  << 
	"     |    Newton-Raphson: " << root1_NR << endl << endl;;

	cout << "f(x) = x^5 - 4x + 4  |  Bounds: -5.0 , 5.0   |   Expected value: -1.59701   |   Bisection: " << root2  << 
	"     |    Newton-Raphson: " << root2_NR << endl << endl;

	cout << "f(x) = 2x^3 + 5x^2 - 4x - 3  |  Bounds: 0.0 , 5.0   |   Expected value: 1   |   Bisection: " << root3  << 
	"     |    Newton-Raphson: " << root3_NR << endl << endl;

	cout << "f(x) = 6x^6 + 0.5x^2 - 0.3x - 3  |  Bounds: 0.0 , 3.0   |   Expected value: 0.884558   |   Bisection: " << root4  << 
	"     |    Newton-Raphson: " << root4_NR << endl << endl;

	cout << "f(x) = x^5 - 10x^3 + 9x  |  Bounds: -5.0, -2.0   |   Expected value: -3 |   Bisection: " << root5  << 
	"     |    Newton-Raphson: " << root5_NR << endl << endl;
 
    return 0;
}
