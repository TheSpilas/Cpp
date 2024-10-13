#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SearchingAlgorithm 
{
public:
    int numberComparisons;
    static int totalComparisons;
    static int totalSearch;
    static double averageComparisons;
    SearchingAlgorithm();
    virtual int search(const vector<int>&, int) = 0;
    int displaySearchResults(ostream& os, int results, int target);
    
};

#endif