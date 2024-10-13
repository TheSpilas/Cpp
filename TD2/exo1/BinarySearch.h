#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include "main.h"

class BinarySearch : public SearchingAlgorithm 
{
public:
    int search(const vector<int>& vec, int target) override;
};

#endif