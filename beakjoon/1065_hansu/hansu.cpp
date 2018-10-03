#include <cstdio>
#include <vector>
#include <map>
using namespace std;
void preProcess(map<int, bool>& judge);
int main() {

    map<int, bool> judge;
    preProcess(judge);

    int N = 0;
    scanf("%d", &N);

    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (judge[i]) {
            result += 1;
        }
    }

    printf("%d\n", result);

    return 0;
}
void preProcess(map<int, bool>& judge) {
    for (int i = 1; i < 100; i++) {
        judge[i] = true;
    }

    vector<int> num(4,0);
    num[2] = 1;

    for (int i = 100; i < 1000; i++) {
        int diffLeft = num[1] - num[0];
        int diffRight = num[2] - num[1];

        if (diffLeft == diffRight) {
            int index = num[0] + num[1] * 10 + num[2] * 100 + num[3] * 1000;
            judge[index] = true;
        }

        num[0] += 1;
        num[1] += num[0] / 10;
        num[2] += num[1] / 10;
        num[3] += num[2] / 10;

        num[0] %= 10;
        num[1] %= 10;
        num[2] %= 10;
    }
}
