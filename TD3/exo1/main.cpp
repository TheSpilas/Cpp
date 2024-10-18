#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;


void countFrequencyBruteForce(const vector<int> &numbers) 
{
    vector<pair<int, int>> frequency;
    
    for (int i = 0; i < numbers.size(); i++) 
    {
        bool found = false;
        for (int j = 0; j < frequency.size(); j++) 
        {
            if (frequency[j].first == numbers[i]) 
            {
                frequency[j].second++;
                found = true;
                break;
            }
        }
        if (!found) 
        {
            pair<int, int> newPair;
            newPair.first = numbers[i];
            newPair.second = 1;
            frequency.push_back(newPair);
        }
    }

    for (int i = 0; i < frequency.size(); i++) 
    {
        cout << "Nombre " << frequency[i].first << " apparaît " << frequency[i].second << " fois" << endl;
    }
}

map<int , int> countFrequencyOptimal ( const vector<int> & numbers ) {
    map<int, int> frequency;
    for (int i = 0; i < numbers.size(); i++) 
    {
        if (frequency.find(numbers[i]) == frequency.end()) 
        {
            frequency[numbers[i]] = 1;
        } 
        else 
        {
            frequency[numbers[i]]++;
        }
    }
    return frequency;
} 

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};
    
    // Test countFrequencyBruteForce
    cout << "Frequency (Brute Force): " << endl;
    countFrequencyBruteForce(numbers);
    
    // Test countFrequencyOptimal
    cout << "\nFrequency (Optimal): " << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto& entry : frequencyMapOptimal) {
        cout << entry.first << " : " << entry.second << " times" << endl;
    }
    
    return 0;
}