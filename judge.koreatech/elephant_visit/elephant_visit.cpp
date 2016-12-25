#include <cstdio>
int main() {
    int xPos = 0;
    scanf("%d", &xPos);

    printf("%d\n", (xPos / 5) + (xPos % 5 == 0 ? 0 : 1));

    return 0;
}
