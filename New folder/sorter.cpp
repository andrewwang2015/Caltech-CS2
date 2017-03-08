/**
 * @file
 * @author The CS2 TA Team <<cs2-tas@ugcs.caltech.edu>>
 * @version 1.0
 * @date 2013-2014
 * @copyright This code is in the public domain.
 *
 * @brief The bubble sort, quick sort, merge sort, and in-place quicksort
 * algorithms (implementation).
 *
 */
#include "sorter.h"

int main(int argc, char* argv[])
{
    // Set up buffers and data input
    std::vector<int> nums;
    std::string line;
    char *filename;
    int sort_type;

    // Ensure that at most one type of sort and at least a filename are specified.
    if (argc > 3 || argc < 2)
    {
        usage();
    }

    // default sort is bubble sort
    //sort_type = BUBBLE_SORT;

    // Figure out which sort to use
    for (int i = 1; i < argc; ++i)
    {
        char *arg = argv[i];
        if (strcmp(arg, "-b") == 0) { sort_type = BUBBLE_SORT; }
        else if (strcmp(arg, "-q") == 0) { sort_type = QUICK_SORT; }
        else if (strcmp(arg, "-m") == 0) { sort_type = MERGE_SORT; }
        else if (strcmp(arg, "-qi") == 0) { sort_type = QUICK_SORT_INPLACE; }
        else { filename = argv[i]; }
    }

    // Read the file and fill our vector of integers
    // THIS FUNCTION IS STUDENT IMPLEMENTED
    readFile(filename, nums);

    switch (sort_type)
    {
        case BUBBLE_SORT:
        print_vector(bubbleSort(nums));
        break;

        case QUICK_SORT:
        print_vector(quickSort(nums));
        break;

        case MERGE_SORT:
        print_vector(mergeSort(nums));
        break;

        case QUICK_SORT_INPLACE:
        quicksort_inplace(nums, 0, nums.size() - 1);
        print_vector(nums);
        break;

        default:
        usage();
        break;
    }
    return 0;
}

/**
 * Usage    Prints out a usage statement and exits.
 */
void usage()
{
    fprintf(stderr, "%s", usage_string);
    exit(1);
}

/**
 * TO STUDENTS: In all of the following functions, feel free to change the
 * function arguments and/or write helper functions as you see fit. Remember to
 * add the function header to sorter.h if you write a helper function!
 */


 /**
 * @brief Code outline of Bubble Sort
 */

/**
 * This version of the bubble sort is slightly optimized by keeping track of
 * the last item swapped with the assumption that all items after the item
 * swapped is in right positions. The k variable here decreases by 1 after 
 * every iteration of the inner for loop because the integers after location k
 * in the array can be assumed to be sorted.
 *
 * Let n be the size of the array. Let cutoff = n-1 = k.
 * FOR i from 1 to n-1:
 *     For j from 0 to cutoff:
            IF array[j] > array[j+1]:
                swap the two elements
        cutoff = k - 1;
 *
 *
 */
std::vector<int> bubbleSort(std::vector<int>  &list)
{
    int n = list.size();
    int k = n - 1;
    int cutoff = n - 1;
    int temp;
    for (int i = 0 ; i < n-1 ; i++){
        for (int j = 0; j < cutoff; j++)
        {
            if (list[j] > list[j+1]){
                temp = list[j];
                list[j] = list [j+1];
                list[j+1] = temp;
            }
            
        }
        cutoff = k -1;
    }



    return list;
}


 /**
 * @brief Code outline of quickSort
 *
 *
 * This function will initially choose its pivot to be the middle of the vector.
 * It will then partition the vector by putting numbers smaller than the pivot to one
 * side and numbers greater than the pivot to the other. These two vectors are then
 * used to recursively call the same method again and then merged to return the initial list, sorted.
 * Base case is if the vector only has one element in which case we just return the inputted list.
 *
 * Initialize two vectors that will be recursively called upon
 * Left will be start of array, Right will be end
 * Take pivot to be the median. Set lower equal to left and upper = right.
 *
 * If base case of 1 element, return the element.
 * WHILE i<=j
*    Iterate through list and if pivot element > element at lower
 *          Increase lower
 *    Iterate through list and if pivot element < upper element
 *          Decrease upper
 *    If lower<=upper  
 *        Swap elements at lower and upper
 *        increase lower , decrease upper
 * Copy elements less than the element at pivot to left vector
 * Copy elements greater than the element at pivot to right vector
 * Recursively call the function on these two vectors
 * Return the merge of left and right
 */




std::vector<int> quickSort(std::vector<int> &list)
{
  std::vector <int> left1;
  std::vector <int> right1;
  if (list.size() <= 1){
    return list;
  }
  int left = 0;
  int right = list.size() - 1;
  int lower = left;
  int upper = right;
  int temp;
  int pivot = (left + right)/2;

 while (lower <= upper) {
    for (int k = 0 ; k < list.size(); k++){
        if (list[pivot] > list[lower]){
            lower++;
        }
        else
        {
            break;  
        }
    }

    for (int k = 0 ; k < list.size(); k++){
        if (list[pivot] < list[upper]){
            upper--;
        }
        else
            {break;}
    }

    if (lower <= upper) {
        temp = list[lower];
        list[lower] = list[upper];
        list[upper] = temp;
        lower++;
        upper--;
    }
}
  for (int m = left; m <= upper; m++){
        left1.push_back(list[m]);
  }

  for (int m = lower; m <= right; m++){
        right1.push_back(list[m]);
  }

  if (left < upper){
     quickSort(left1);
  }

  if (lower < right){
     quickSort(right1);
  }

return merge(left1, right1);

}

 /**
 * @brief Code outline of mergeSort: Note the merging helper function is described separately
 *
 *
 * This function will divide the inputted vector into two separate vectors of ~equal size. It will recursively
 * call itself (the function) on both halves and merges both halves (using the helper function which is described
 * below . The base case is when the size of a vector is just one item in which case it will
 * return.
 *
 * 
 * If length of list <= 1
 *    return list
 * Take middle to be the size / 2
 * Put elements to left of middle to vector 'left' and the elements to the right of middle to vector 'right'
 * Recursively call merge sort on left and right side.
 * Merge left and right side.
 * return merged list.
 */

std::vector<int> mergeSort(std::vector<int> &list)
{
    std::vector <int> left;
    std::vector <int> right;
    if (list.size() <= 1){
        return list;
    }
    int middle = list.size() / 2;
    for (int i = 0; i < middle; i++){
        left.push_back(list[i]);
    }
    for (int j = middle; j < list.size(); j++){
        right.push_back(list[j]);
    
    }
    mergeSort(left);
    mergeSort(right);
    list = merge(left, right);
    return list;
}



/**
 * @brief Helper "merge" function for mergeSort
 */

/**
 * This function takes two vectors and effectively merges them.
 * Basically, it will create two counters, one for each array
 * and compare corresponding entries and put the smaller one in a new array.
 * It will then put leftover items of both arrays onto the end of the new array.
 *
 * LEFT = one array to merge, RIGHT = other array to merge, NEW = array that has correct order
 * WHILE (items in LEFT and items in RIGHT)
 *    compare items and put smaller array into new array
 *    increase counter corresponding to array that had item placed in new array
 * Put leftover items onto end of new array
 }
 */
std::vector<int> merge(std::vector<int> &left, std::vector<int> &right)
{
    int leftI = 0;
    int rightI = 0;
    std::vector <int> newArray;

    while (leftI < left.size() && rightI < right.size())
    {
        if (left[leftI] <right[rightI]){
            newArray.push_back(left[leftI]);
            leftI ++;
        }

        else
        {
            newArray.push_back(right[rightI]);
            rightI ++;
        }
    }

    for (int i = leftI ; i < left.size(); i++){
        newArray.push_back(left[i]);
    }

    for (int j = rightI; j < right.size(); j++){
        newArray.push_back(right[j  ]);
    }       
    left = newArray;
    return left;
}

/*
 * quicksort_inplace:  In-place version of the quicksort algorithm. Requires
 *              O(1) instead of O(N) space, same time complexity. Each call of
 *              the method partitions the list around the pivot (an item taken
 *              from the middle of the array) with items left of the pivot
 *              smaller than it and items to its right larger than it. Then the
 *              method recursively sorts the left and right portions of the list
 *              until it reaches its base case: a list of length 1 is already
 *              sorted.
 *
 * @param list: pointer to integer array to be sorted
 * @returns:    Nothing, the array is sorted IN-PLACE.
 *
 *
 * @brief Code outline of quickSort in Place
 *
 *
 *
 *
 * 
 * Left will be start index, Right will be end index
 * Take pivot to be the median. Set lower equal to left and upper = right.
 * 
 * WHILE lower<=upper
 *    Iterate through list and if pivot element > element at lower
 *          Increase lower
 *    Iterate through list and if pivot element < upper element
 *          Decrease upper
 *    If lower<=upper  
 *        Swap elements at lower and upper
 *        increase lower , decrease upper
 * If left < upper
 *    recursively call function using left and upper as parameters
 * If lower < right
 *    recursively call function using lower and right as parameters
 */
 
void quicksort_inplace(std::vector<int> &list, int left, int right)
{

  int temp;
  int lower = left;
  int upper = right;
  int pivot = (left + right)/2;

  while (lower <= upper) {
    for (int k = 0 ; k < list.size(); k++){
        if (list[pivot] > list[lower]){
            lower++;
        }
        else
        {
            break;  
        }
    }

    for (int k = 0 ; k < list.size(); k++){
        if (list[pivot] < list[upper]){
            upper--;
        }
        else
            {break;}
    }

    if (lower <= upper) {
        temp = list[lower];
        list[lower] = list[upper];
        list[upper] = temp;
        lower++;
        upper--;
    }

  }

  if (left < upper){
     quicksort_inplace(list, left, upper);
  }

  if (lower < right){
     quicksort_inplace(list, lower, right);
  }

return;
}

