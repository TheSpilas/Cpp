#include "main.h"
#include "LinearSearch.h"
#include "JumpSearch.h"
#include "BinarySearch.h"

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparisons = 0.0;
SearchingAlgorithm::SearchingAlgorithm() {}

int SearchingAlgorithm::displaySearchResults(ostream& os, int results, int target) 
{
    totalComparisons += numberComparisons;
    totalSearch++;
    averageComparisons = static_cast<double>(totalComparisons) / totalSearch;

    if (results != -1) 
    {
        os << "Elément " << target << " trouvé à l'index :" << results << endl;
    } 
    else 
    {
        os << "Elément " << target << " n'a pas été trouvé" << endl;
    }
    os << "Total comparaisons: " << totalComparisons << endl;
    os << "Comparaisons moyenne: " << averageComparisons << endl;

    return results;
}

int main() 
{
    vector<int> data = {1, 2, 3, 4, 5};
    int target = 3;

    cout << "########################## LinearSearch #########################" << endl;
    LinearSearch linearSearch;
    int linearIndex = linearSearch.search(data, target);
    linearSearch.displaySearchResults(cout, linearIndex, target);
    cout << "########################## JumpSearch #########################" << endl;
    
    JumpSearch jumpSearch;
    int jumpIndex = jumpSearch.search(data, target);
    jumpSearch.displaySearchResults(cout, jumpIndex, target);

    cout << "########################## BinarySearch #########################" << endl;
    BinarySearch binarySearch;
    int binaryIndex = binarySearch.search(data, target);
    binarySearch.displaySearchResults(cout, binaryIndex, target);

    return 0;
}