#include <string>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

bool comp(const string& l, const string& r) {
    if (l + r > r + l) {
        return true;
    }

    return false;
}

string solution(vector<int> numbers) {
    vector<string> strNumbers;
    for (int number : numbers) {
        strNumbers.push_back(to_string(number));
    }

    sort(strNumbers.begin(), strNumbers.end(), comp);
    
    string answer = "";
    for (const string &strNumber : strNumbers) {
        answer += strNumber;
    }

    if (answer[0] == '0') {
        return "";
    }

    return answer;
}

void testExample() {
    assert("6210" == solution({6, 10, 2}));
    assert("9534330" == solution({3, 30, 34, 5, 9}));
    assert("33043030301300" == solution({3, 30, 30, 300, 301, 304}));
}

int main() {
    testExample();

    return 0;
}