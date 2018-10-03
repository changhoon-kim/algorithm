#include <cstdio>
int main() {
    int N = 0, F = 0;
    scanf("%d %d", &N, &F);

    int fixed = (N / 100) * 100;

    if (fixed % F == 0) {
        printf("%02d\n", fixed % 100);
    }
    else {
        printf("%02d\n", (((fixed / F) + 1) * F) % 100);
    }

    return 0;
}
