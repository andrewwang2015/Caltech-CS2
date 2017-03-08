#include <vector>
#include "structs.h"
#include <iostream>
using namespace std;

int addLeftMost(vector<Tuple*> points)
{
    int least = 0;
    int current;
    for (int i = 0; i < points.size(); i++){
        current = points[i] -> x;
        if (current < least){
            least = current;
        }
    }

    for (int i = 0; i < points.size(); i++){
        if (points[i] -> x == least)
        {

            return i;
        }

    }
}

bool determineIfOnHull(Tuple* point1, Tuple* point2, Tuple* point3)
{
    int line1_x = point2->x - point1->x;
    int line2_x = point3->x - point1->x;
    int line1_y = point2->y - point1->y;
    int line2_y = point3->y - point1->y;

    int crossP = (line1_x * line2_y - line2_x * line1_y);

    if (crossP >= 0)
    {
        return true;
    }

    else{
        return false;
    }

}



int main()
{
	vector<Tuple*> points;
    points.push_back(new Tuple(7, 7));
    points.push_back(new Tuple(7, -7));
    points.push_back(new Tuple(-7, -7));
    points.push_back(new Tuple(-7, 7));
    points.push_back(new Tuple(9, 0));
    points.push_back(new Tuple(-9, 0));
    points.push_back(new Tuple(0, 9));
    points.push_back(new Tuple(0, -9));
 




{
    int p1;
    int count = 0;
    p1 = addLeftMost(points);
    int p1_copy = p1;
    int initial = 0;
    int num = 0;
    
    while (num < points.size() && initial < 1){
        num ++;
        for (int i = 0; i < points.size(); i++){
        
        count = 0;
        for (int j = 0; j < points.size(); j++){
            bool test = determineIfOnHull( points[p1],  points[i], points[j]);
            if (test == false)
            {
                break;
            }
            if (test == true)
            {
                count ++;
            }
        }
        if (count == points.size())
            {

            p1 = i;
            points[p1] ->printTuple();
            if (p1 == p1_copy){
                initial ++;
            }

            }
        }
    } 

    return 0;
}
}




