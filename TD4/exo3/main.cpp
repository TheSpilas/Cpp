#include <iostream>
#include <queue>
#include <stack>
#include <cctype>

using namespace std ;

bool isPalindrome ( const string& input ) {
    stack<char> pile;
    queue<char> file;

    for (char c : input) {
        if (isalpha(c)) {
            pile.push(tolower(c));
            file.push(tolower(c));
        }
    }

    while (!pile.empty() && !file.empty()) {
        if (pile.top() != file.front()) {
            return false;
        }
        pile.pop();
        file.pop();
    }

    return pile.empty() && file.empty();
}

int main() {
    cout << boolalpha;
    cout << "Is 'racecar' a palindrome? " << isPalindrome("racecar") << endl;
    cout << "Is 'hello' a palindrome? " << isPalindrome("hello") << endl;
    return 0;
}