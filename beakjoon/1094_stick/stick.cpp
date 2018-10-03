#include <cstdio>
#include <vector>
using namespace std;
vector<int> lengths = {64, 32, 16, 8, 4, 2, 1};
int getNumOfStick(int X, int index, int count);
int main() {
    int X = 0;
    scanf("%d", &X);

    printf("%d\n", getNumOfStick(X, 0, 0));

    return 0;
}
int getNumOfStick(int X, int index, int count) {
    if (X == 0) {
        return count;
    }

    if (lengths[index] > X) {
        return getNumOfStick(X, index + 1, count);
    }
    else {
        return getNumOfStick(X - lengths[index], index + 1, count + 1);
    }
}
