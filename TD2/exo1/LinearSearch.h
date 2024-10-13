#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include "main.h"

class LinearSearch : public SearchingAlgorithm 
{
public:
    int search(const vector<int>& vec, int target) override;
};

#endif