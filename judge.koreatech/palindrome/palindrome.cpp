#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
bool isPalindrome(string &str);
bool isAlpha(string &currChar);
bool upperCase(string &currChar);
char getLowerCase(string &currChar);
void convertFormat(string &str);
int main() {
    int nCase = 0;
    cin >> nCase;
    cin.ignore();

    while(nCase--) {
        char buff[1001];
        cin.getline(buff, sizeof(buff));
        string str(buff);

        convertFormat(str);
        if (isPalindrome(str)) {
            printf("true\n");
        }
        else {
            printf("false\n");
        }
    }

    return 0;
}
void convertFormat(string &str) {
    string newStr;
    int size = str.size();
    for (int i = 0; i < size; i++) {
        string currChar = str.substr(i, 1);
        if (isAlpha(currChar) == false) continue;
        if (upperCase(currChar)) currChar = getLowerCase(currChar);
        newStr.append(currChar);
    }

    str = newStr;
}
bool isPalindrome(string &str) {
    string reverseStr = str;
    reverse(reverseStr.begin(), reverseStr.end());

    if (reverseStr == str) return true;
    return false;
}
bool isAlpha(string &currChar) {
    if (upperCase(currChar))
        return true;
    if (97 <= currChar[0] && currChar[0] <= 122) // a ~ z
        return true;
    return false;
}
bool upperCase(string &currChar) {
    if (65 <= currChar[0] && currChar[0] <= 90) // A ~ Z
        return true;
    return false;
}
char getLowerCase(string &currChar) {
    return currChar[0] + 32;
}
