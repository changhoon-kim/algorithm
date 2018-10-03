#include <cstdio>
#include <vector>
using namespace std;
int getEarthWorm();
void dfs(int row, int col);
vector<vector<int> > farm;
int height, width;
int main() {
    int nCase = 0;
    scanf("%d", &nCase);

    while (nCase--) {
        int nCabbage = 0;
        scanf("%d %d %d", &width, &height, &nCabbage);

        farm = vector<vector<int> >(height, vector<int>(width, 0));

        for (int i = 0; i < nCabbage; i++) {
            int row = 0, col = 0;
            scanf("%d %d", &col, &row);

            farm[row][col] = 1;
        }

        printf("%d\n", getEarthWorm());
    }

    return 0;
}
int getEarthWorm() {
    int nEarthWorm = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (farm[i][j] == 1) {
                nEarthWorm += 1;
                dfs(i, j);
            }
        }
    }

    return nEarthWorm;
}
void dfs(int row, int col) {
    farm[row][col] = 0;

    int directionRow[] = {1, 0, -1, 0};
    int directionCol[] = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++) {
        int checkRow = row + directionRow[i];
        int checkCol = col + directionCol[i];

        if (checkRow < 0 || checkRow >= height) continue;
        if (checkCol < 0 || checkCol >= width) continue;

        if (farm[checkRow][checkCol] == 1)
            dfs(checkRow, checkCol);
    }
}
