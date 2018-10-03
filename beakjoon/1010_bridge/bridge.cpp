#include <cstdio>
using namespace std;
int ways[30][30];
void preProcessing();

int main() {
    preProcessing();

    int nCase = 0;
    scanf("%d", &nCase);

    while (nCase--) {
        int N = 0, M = 0;
        scanf("%d %d", &N, &M);

        printf("%d\n", ways[N][M]);
    }

    return 0;
}

void preProcessing() {
    for (int i = 1; i < 30; i++) {
        for (int j = i; j < 30; j++) {
            if (i == 1) ways[i][j] = j;
            else ways[i][j] = ways[i][j-1] + ways[i-1][j-1];
        }
    }
}
