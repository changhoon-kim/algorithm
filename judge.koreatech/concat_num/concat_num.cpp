#include <cstdio>
#include <vector>
#include <map>
using namespace std;
void preProcess();
int getPositionNumber(int position);
int getPositionNumberInner(int currentNum, int remainCount);
int getDivUnit(int position);
int getDigit(int position);
int getBase(int digit);
vector<int> divList;
map<int, int> digitMap;
int main() {
    preProcess();
    int nCase = 0;
    scanf("%d", &nCase);

    while(nCase--) {
        int position = 0;
        scanf("%d", &position);

        printf("%d\n", getPositionNumber(position));
    }

    return 0;
}
void preProcess() {
    vector<int> divListLoc{0, 9, 189, 2889, 38889,
                           488889, 5888889, 68888889,
                           788888889, 2147483647};
    divList = divListLoc;

    int size = divList.size();
    for (int i = 1; i < size - 1; i++) {
        digitMap[divList[i]] = i + 1;
    }
}
int getPositionNumber(int position) {
    int divUnit = getDivUnit(position);
    if (divUnit == 0) return position;
    int remainCount = position - divUnit;
    int digit = getDigit(divUnit);
    int digitCount = remainCount / digit - 1;
    remainCount = remainCount % digit;
    int currentNum = getBase(digit) + digitCount;
    if (remainCount == 0) return currentNum % 10;
    return getPositionNumberInner(currentNum + 1, remainCount);
}
int getPositionNumberInner(int currentNum, int remainCount) {
    vector<int> num(100);
    while (currentNum) {
        num.push_back(currentNum % 10);
        currentNum /= 10;
    }
    return num[num.size() - remainCount];
}
int getDivUnit(int position) {
    int size = divList.size();
    for (int i = 1; i < size; i ++) {
        if (position <= divList[i]) return divList[i-1];
    }
    return divList[0];
}
int getDigit(int divUnit) {
    return digitMap[divUnit];
}
int getBase(int digit) {
    int base = 1;
    for (int i = 0; i < digit - 1; i++) {
        base *= 10;
    }
    return base;
}
