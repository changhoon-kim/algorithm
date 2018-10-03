#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int x = 0, y = 0, w = 0, h = 0;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    int diffHorizon = min(x, w - x);
    int diffVertical = min(y, h - y);
    int result = min(diffHorizon, diffVertical);

    printf("%d\n", result);

    return 0;
}
