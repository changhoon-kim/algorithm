#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int getFastestPath(int sRow, int sCol);
bool canMove(int row, int col);
int width, height;
int rowDir[] = {1, 0, -1, 0};
int colDir[] = {0, -1, 0, 1};
vector<vector<char> > schoolMap;
int main() {
    int nCase = 0;
    scanf("%d", &nCase);

    while(nCase--) {
        scanf("%d %d", &height, &width);
        schoolMap = vector<vector<char> >(height, vector<char>(width, 0));

        int sRow = 0, sCol = 0;
        for (int i = 0; i < height; i++) {
            getchar(); // for flush '\n'
            for (int j = 0; j < width; j++) {
                scanf("%c", &schoolMap[i][j]);
                if (schoolMap[i][j] == 'S') {
                    sRow = i;
                    sCol = j;
                }
            }
        }

        printf("%d\n", getFastestPath(sRow, sCol));
    }

    return 0;
}
int getFastestPath(int sRow, int sCol) {
    vector<vector<int> > distanceMap(height, vector<int>(width, -1));
    distanceMap[sRow][sCol] = 0;

    queue<int> rowQue;
    queue<int> colQue;
    rowQue.push(sRow);
    colQue.push(sCol);

    int result = -1;
    while (rowQue.size() > 0) {
        int row = rowQue.front();
        int col = colQue.front();
        rowQue.pop();
        colQue.pop();

        if (schoolMap[row][col] == 'E') {
            result = distanceMap[row][col];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nextRow = row + rowDir[i];
            int nextCol = col + colDir[i];
            if (canMove(nextRow, nextCol) && distanceMap[nextRow][nextCol] < 0) {
                rowQue.push(nextRow);
                colQue.push(nextCol);
                distanceMap[nextRow][nextCol] = distanceMap[row][col] + 1;
            }
        }
    }

    return result;
}
bool canMove(int row, int col) {
    if (row < 0 || row >= height) return false;
    if (col < 0 || col >= width) return false;
    if (schoolMap[row][col] == '#') return false;
    return true;
}
