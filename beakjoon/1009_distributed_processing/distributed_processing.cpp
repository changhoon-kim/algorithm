#include <cstdio>
using namespace std;
int getFirstDigit(int a, int b);
int main() {
    int nCase = 0;
    scanf("%d", &nCase);

    while (nCase--) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);

        int firstDigit = getFirstDigit(a, b);
        printf("%d\n", firstDigit);
    }

    return 0;
}

int getFirstDigit(int a, int b) {
    int result = 1;
    while (b--) {
        result *= a;
        result %= 10;
    }

    return result ? result : 10;
}
