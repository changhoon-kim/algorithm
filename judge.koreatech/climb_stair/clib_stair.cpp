#include <cstdio>
#include <vector>
using namespace std;
void calc(vector<int> &stair);
int main() {
    int nCase = 0;
    scanf("%d", &nCase);

    while(nCase--) {
        int nStair = 0;
        scanf("%d", &nStair);

        vector<int> stair(nStair + 1, 0);
        calc(stair);
        printf("%d\n", stair[nStair]);
    }

    return 0;
}
void calc(vector<int> &stair) {
    int size = stair.size();
    stair[0] = 1;
    for(int i = 0; i < size - 2; i++) {
        stair[i+1] += stair[i];
        stair[i+2] += stair[i];
    }
    stair[size-1] += stair[size-2];
}
