#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int> > stage;
vector<vector<int> > cal;
int height;
int width;
int solution();
const int DIR_NORTH = 0x01;
const int DIR_EAST =  0x02;
const int DIR_SOUTH = 0x04;
const int DIR_WEST =  0x08;
void mark(int row, int col, int direction);
int main() {
    scanf("%d %d", &width, &height);
    stage = vector<vector<int> >(height, vector<int>(width, 0));
    cal = vector<vector<int> >(height, vector<int>(width, 0));

    for (int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            scanf("%d", &stage[i][j]);
            if (stage[i][j]) cal[i][j] = -1;
        }
    }

    printf("%d\n", solution());

    return 0;
}
int solution() {

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (stage[i][j]) {
                for (int k = 0; k < 4; k++) {
                    mark(i, j, k);
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < height; i++) {
        for( int j = 0; j < width; j++) {
            if (cal[i][j] > 0) {
                int bit = 1;
                for (int k = 0; k < 4; k++) {
                    if (bit & cal[i][j]) result += 1;
                    bit <<= 1;
                }
            }
        }
    }

    return result;
}
void mark(int row, int col, int direction) {
    if (direction == 0) { // north
        if (row == 0) return;
        for (int i = row - 1; i >= 0; i--) {
            if (cal[i][col] < 0) break;
            cal[i][col] += DIR_NORTH;
        }
    }
    else if (direction == 1) { // east
        if (col >= width) return;
        for (int i = col + 1; i < width; i++) {
            if (cal[row][i] < 0) break;
            cal[row][i] += DIR_EAST;
        }
    }
    else if (direction == 2) { // south
        if (row >= height) return;
        for (int i = row + 1; i < height; i++) {
            if (cal[i][col] < 0) break;
            cal[i][col] += DIR_SOUTH;
        }
    }
    else { // west
        if (col == 0) return;
        for (int i = col - 1; i >= 0; i--) {
            if (cal[row][i] < 0) break;
            cal[row][i] += DIR_WEST;
        }
    }
}
