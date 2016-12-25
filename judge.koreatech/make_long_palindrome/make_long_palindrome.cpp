#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
void toLowerCase(string &str);
int main() {
    int nCase = 0;
    scanf("%d", &nCase);

    while(nCase--) {
        string str;
        cin >> str;

        toLowerCase(str);

        map<char, int> counterMap;
        int strSize = str.size();
        for (int i = 0; i < strSize; i++) {
            counterMap[str[i]]++;
        }

        int result = 0;
        int oddMax = 0;
        map<char, int>::iterator iter = counterMap.begin();
        for ( ; iter != counterMap.end(); iter++) {
            int &count = iter->second;
            if (count % 2 == 0) {
                result += count;
            }
            else {
                result += count - 1;
                oddMax = max(oddMax, count);
            }
        }

        if (oddMax) result += 1;

        printf("%d\n", result);
    }

    return 0;
}
void toLowerCase(string &str) {
    int size = str.size();
    for (int i = 0; i < size; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}
