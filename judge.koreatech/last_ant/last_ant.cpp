#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
#include <map>
using namespace std;
int getAllAntsFallTime(vector<pair<int, int> >& antInfoList, int pollLength);
const int LEFT = -1;
const int RIGHT = 1;
int MAX_INT;
int main() {
    MAX_INT = numeric_limits<int>::max();

    int nCase = 0;
    scanf("%d", &nCase);

    while(nCase--) {
        int nAnts = 0, pollLength = 0;
        scanf("%d %d", &nAnts, &pollLength);

        vector<pair<int, int> > antInfoList(nAnts);
        for (int i = 0; i < nAnts; i++) {
            int pos = 0, dir = 0;
            scanf("%d %d", &pos, &dir);
            pair<int, int> antInfo = {pos, dir};
            antInfoList[i] = antInfo;
        }

        printf("%d\n", getAllAntsFallTime(antInfoList, pollLength));
    }

    return 0;
}
int getAllAntsFallTime(vector<pair<int, int> >& antInfoList, int pollLength) {
    int nAnts = antInfoList.size();

    int leftMaxPos = 0, rightMinPos = MAX_INT;
    for (int i = 0; i < nAnts; i++) {
        if (antInfoList[i].second == RIGHT) {
            rightMinPos = min(rightMinPos, antInfoList[i].first);
        }
        else { // LEFT
            leftMaxPos = max(leftMaxPos, antInfoList[i].first);
        }
    }

    rightMinPos = rightMinPos == MAX_INT ? 0 : pollLength - rightMinPos;

    return max(leftMaxPos, rightMinPos);
}
