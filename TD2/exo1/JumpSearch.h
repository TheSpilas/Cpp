#ifndef JUMPSEARCH_H
#define JUMPSEARCH_H

#include "main.h"

class JumpSearch : public SearchingAlgorithm 
{
public:
    int search(const vector<int>& vec, int target) override;
};

#endif