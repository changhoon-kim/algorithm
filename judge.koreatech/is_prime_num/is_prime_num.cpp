#include <cstdio>
#include <cmath>
bool isPrime(int num);
int main() {
    int num = 0;
    scanf("%d", &num);

    if (isPrime(num)) {
        printf("prime\n");
    }
    else {
        printf("not prime\n");
    }

    return 0;
}
bool isPrime(int num) {
    if (num <= 1) return false;
    int maxRange = sqrt(num);
    for (int i = 2; i <= maxRange; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
