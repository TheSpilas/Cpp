#include "LinearSearch.h"

int LinearSearch::search(const vector<int>& vec, int target) 
{
    numberComparisons = 0;
    for (size_t i = 0; i < vec.size(); ++i) 
    {
        numberComparisons++;
        if (vec[i] == target) 
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}