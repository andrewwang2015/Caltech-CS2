/**
 * @file
 * @author The CS2 TA Team <<cs2-tas@ugcs.caltech.edu>>
 * @version 1.0
 * @date 2013-2014
 * @copyright This code is in the public domain.
 *
 * @brief The gift wrapping and Graham scan convex hull algorithms
 * (implementation).
 *
 */
#include "HullAlgorithms.h"


/**
 * TO STUDENTS: In all of the following functions, feel free to change the
 * function arguments and/or write helper functions as you see fit. Remember to
 * add the function header to HullAlgorithms.h if you write a helper function!
 *
 * Our reference implementation has four helper functions and the function(s)
 * copied over from angleSort.cpp.
 */

 /**
  * The idea behind the gift wrap is that it will first find one point that we know
  * to be on the hull (either leftmost, rightmost, topmost, or bottommost point). 
  * Using this as a starting point, we then iterate through every other point via pairs.
  * This allows us to test whether or not a tested point is on the hull. For the tested
  * point to be on the hull, all other points that it is paired with must be on the left
  * of the line between the tested point and the point we know to be on the hull. We do this
  * test via a cross product of two vectors (one vector connects known point to tested point
  * and the other vector connects known point to the other point of the pair). If all other points
  * are to the left, then we know that the tested point is on the hull. Now this point is known
  * to be on the hull and we move onto a new pair of points for testing and repeat the process until
  * the hull receives the same beginning point, in which case, we know that the hull has been closed.
  *
  * 
 */
void DoGiftWrap(vector<Tuple*> points, ConvexHullApp *app)
{
    
    int p1;
    int count = 0;
    p1 = addBottomMost(points, app);
    int p1_copy = p1;
    int initial = 0;
    int num = 0;
    app->add_to_hull(points[p1]);
    while (num < points.size() && initial < 2){
        num ++;
        for (int i = 0; i < points.size(); i++){
            
            count = 0;
            for (int j = 0; j < points.size(); j++){
                bool test = determineIfOnHull( points[p1],  points[i], points[j], app);
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
                
                app->add_to_hull(points[i]);
                if (p1 == p1_copy){
                    initial ++;
                }

                }
        }
    } 

    return;

}

/**
  * This function inputs the vector of points and returns the
  * index of the point that we know to be part of the hull
  * (bottom most, relative to the cartesian coordinates so top most in computer coordinates).
  */

int addBottomMost(vector<Tuple*> points, ConvexHullApp *app)
{
    int least = 0;
    int current;
    for (int i = 0; i < points.size(); i++){
        current = points[i] -> y;
        if (current > least){
            least = current;
        }
    }

    for (int i = 0; i < points.size(); i++){
        if (points[i] -> y == least)
        {
            
            return i;
        }

    }
}


int addTopMost(vector<Tuple*> points, ConvexHullApp *app)
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

/**
  * This function inputs three tuples of points and calculates their cross product
  * to determine if point 2 can be part of the hull using vectors between point 1, point 3 and
  * point 1, point 2 to determine if point 3 is to the left of the line between point 1 and point 2
  * or not. Returns bool corresponding to the answer.
  */



bool determineIfOnHull(Tuple* point1, Tuple* point2, Tuple* point3, ConvexHullApp *app)
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



/**
 * This is taken from angle sort and sorts angles and changes the corresponding list to reflect the order changes
 * in angles (or list)
 */

void sort(vector<double> &list, vector<Tuple*> &list2, int left, int right)
{
    

  int i = left, j = right;
  double temp;
  Tuple* temp2 = new Tuple (0,0);

  int pivot = (left + right)/2;

  while (i <= j) {

    while (list[pivot] > list[i]){
        i++;
    }

    while (list[pivot] < list[j]){
        j--;
    }

    if (i <= j) {
        temp = list[i];
        temp2 = list2[i];
        list[i] = list[j];
        list2[i] = list2[j];
        list[j] = temp;
        list2[j] = temp2;
        i++;
        j--;
    }

  }

  if (left < j){
     sort(list, list2, left, j);
  }

  if (i < right){
     sort(list, list2, i, right);
  }

       

return;


}


/* This Graham scan will find the lowest point in the set of points and then sort the points with respect to the angles they make with the lowest point.
 * Then going through the corresponding list of sorted angles, points will be tested in sets of 3 to determine if there is a left turn or right turn taking 
 * place in determining if it's on the hull. Do this until the starting point is returned to in which case the hull drawing is complete.
 */

void DoGrahamScan(vector<Tuple*> points, ConvexHullApp *app)
{

    vector <double> angles;
    int p1;
    int count = 0;
    p1 = addTopMost(points, app);

    app->add_to_hull(points[p1]);
    for (int i = 0; i < points.size() ; i++){
    	angles.push_back(points[i]->angle_wrt_x_axis());
    }

    sort(angles, points, 0, points.size()-1);
    
    for (int i = 0 ; i < angles.size(); i ++){
    	bool test = determineIfOnHull(points[p1], points[i], points[i+1],app);
    	if (test == false){
    		break;
    	}
    	if (test == true){
    		p1 = i;
    		app->add_to_hull(points[i]);
    		
    	}
    }


    return;



}
