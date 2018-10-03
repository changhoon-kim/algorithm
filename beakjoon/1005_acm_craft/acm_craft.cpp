#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int> > ruleMap;
vector<int> buildTimes;
vector<int> cache;
int nBuilding, nRule;
int getCompleteTime(int buildingNumber);
int main() {
    int nCase = 0;
    scanf("%d", &nCase);

    while (nCase--) {
        scanf("%d %d", &nBuilding, &nRule);

        cache = vector<int>(nBuilding + 1, 0);
        buildTimes = vector<int>(nBuilding + 1, 0);
        for (int i = 1; i <= nBuilding; i++) {
            scanf("%d", &buildTimes[i]);
        }

        ruleMap = vector<vector<int> >(nBuilding + 1, vector<int>(nBuilding + 1, 0));
        for (int i = 0; i < nRule; i++) {
            int src = 0, dst = 0;
            scanf("%d %d", &src, &dst);
            ruleMap[src][dst] = 1;
        }

        int buildingNumber = 0;
        scanf("%d", &buildingNumber);

        printf("%d\n", getCompleteTime(buildingNumber));
    }

    return 0;
}
int getCompleteTime(int buildingNumber) {
    if (cache[buildingNumber]) {
        return cache[buildingNumber];
    }

    if (buildingNumber == 1) {
        return buildTimes[1];
    }

    int completeTime = 0;
    for (int i = 1; i <= nBuilding; i++) {
        if (ruleMap[i][buildingNumber]) {
            completeTime = max(completeTime,
                        buildTimes[buildingNumber] + getCompleteTime(i));
        }
    }

    cache[buildingNumber] = completeTime;

    return completeTime;
}
