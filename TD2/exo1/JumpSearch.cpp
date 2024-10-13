#include "JumpSearch.h"
#include <cmath>

int JumpSearch::search(const vector<int>& vec, int target) 
{
    numberComparisons = 0;
    size_t n = vec.size();
    size_t step = sqrt(n);
    size_t prev = 0;

    while (vec[min(step, n) - 1] < target) 
    {
        numberComparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) 
        {
            return -1;
        }
    }

    for (size_t i = prev; i < min(step, n); ++i) 
    {
        numberComparisons++;
        if (vec[i] == target) 
        {
            return static_cast<int>(i);
        }
    }

    return -1;
}