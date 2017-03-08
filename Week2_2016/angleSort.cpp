/**
 * @file
 * @author The CS2 TA Team <<cs2-tas@ugcs.caltech.edu>>
 * @version 1.0
 * @date 2013-2014
 * @copyright This code is in the public domain.
 *
 * @brief An example of sorting (x, y) pairs by angle.
 *
 */
#include "structs.h"
#include <vector>

using namespace std;

// TODO Modify one of your sorting functions (bubble sort not permitted) and
// implement it here. Add extra arguments as needed.

/**
 * @brief sorts a list and its corresponding list by shifting corresponding elements
 *
 *
 * @param list: list to sort, list2: list that should be reshuffled based on list, left: start index, right: end index
 * returns: void
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

int main(int argc, char const *argv[])
{
    vector<double> angles {4.2, 2.8, 1.4, 5.0, 3.3};
    vector<Tuple*> points;
    // Print the initial points and angles
    for (unsigned int i = 0; i < angles.size(); ++i)
    {
        points.push_back(new Tuple(i, i));
    }
    for (vector<Tuple*>::iterator i = points.begin(); i != points.end(); ++i)
    {
        (*i)->printTuple();
    }
    for (vector<double>::iterator i = angles.begin(); i != angles.end(); ++i)
    {
        printf("%g\n", *i);
    }

    // Now sort them with respect to angle (points[i] corresponds to angle[i])

    /** THIS IS THE ONLY LINE OF THE MAIN LOOP YOU NEED TO MODIFY. */
    sort(angles,points, 0 , points.size()-1);
    /** REPLACE THE LINE ABOVE WITH A CALL TO YOUR SORTING FUNCTION. */

    // and print out the new points and angles
    for (vector<Tuple*>::iterator i = points.begin(); i != points.end(); ++i)
    {
        (*i)->printTuple();
    }
    for (vector<double>::iterator i = angles.begin(); i != angles.end(); ++i)
    {
        printf("%g\n", *i);
    }

    // Don't want to leak memory...
    // Either of the below implementations works
    // for (std::vector<Tuple*>::iterator i = points.begin(); i != points.end(); ++i)
    // {
    //     delete (*i);
    // }
    for (unsigned int i = 0; i < points.size(); ++i)
    {
        delete points[i];
    }
    return 0;
}
