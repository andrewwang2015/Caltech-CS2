/**
 * @file
 * @author The CS2 TA Team <<cs2-tas@ugcs.caltech.edu>>
 * @version 1.0
 * @date 2013-2014
 * @copyright This code is in the public domain.
 *
 * @brief Student implementation of line algorithm.
 *
 */
#include "LineAlgorithm.h"
 using namespace std;
 #include <stdlib.h>

/**
 * TODO: Implement a line algorithm of your choice here.
 */
vector<Tuple> line(Tuple* p1, Tuple* p2)
{
	vector<Tuple> v;
	int y_inc;
	v.push_back(p1);
	int p1_x = p1->x;
	int p1_y = p1->y;
	int p2_x = p2->x;
	int p2_y = p2->y;
	int y_init = p1->y;
	int diff_x = abs(p1_x - p2_x);
	int diff_y = abs(p1_y - p2_y);

	float e = diff_x / 2.0;
	if (p2_y > p1_y){
		y_inc = 1;
	}
	else
	{
		y_inc = -1;
	}

	for (int i = p1_x ; i < p2_x; i++){
		if (diff_y > diff_x){
			Tuple add = new Tuple(y_init, i);
			v.push_back(add);
		}

		else {
			Tuple add = new Tuple (i, y_init);
			v.push_back(add);
		}

		e = e - diff_y;
		if (e < 0){
			e += diff_x;
			y_init += y_inc;
			
		}
	}    
    return v;
}
