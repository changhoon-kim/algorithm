#include <cstdio>
int main() {
    int N = 0, kim = 0, lim = 0;
    scanf("%d %d %d", &N, &kim, &lim);

    int round = 0;
    for ( ; kim != lim; round++) {
        kim = kim - kim / 2;
        lim = lim - lim / 2;
    }

    printf("%d\n", round);

    return 0;
}
