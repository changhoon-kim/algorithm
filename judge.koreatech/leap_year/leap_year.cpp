#include <cstdio>
bool isLeapYear(int year);
int main() {
    int nCase = 0;
    scanf("%d", &nCase);

    while(nCase--) {
        int year = 0;
        scanf("%d", &year);

        if (isLeapYear(year)) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }

    return 0;
}
bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}
