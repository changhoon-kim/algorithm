#include <cstdio>
#include <vector>
using namespace std;
void printAnswerFormat(vector<int> &positions);
int main() {
    int nCase = 0;
    scanf("%d", &nCase);

    while(nCase--) {
        int num = 0;
        scanf("%d", &num);

        vector<int> positions;
        positions.reserve(32);
        int bit = 1;
        for (int i = 0; i < 32; i++) {
            if (num & bit) positions.push_back(i);
            bit <<= 1;
        }

        printAnswerFormat(positions);
    }

    return 0;
}
void printAnswerFormat(vector<int> &positions) {
    if (positions.empty()) {
        printf("-1\n");
    }
    else {
        int size = positions.size();
        for (int i = 0; i < size; i++) {
            if (i != size - 1) {
                printf("%d ", positions[i]);
            }
            else {
                printf("%d\n", positions[i]);
            }
        }
    }
}
