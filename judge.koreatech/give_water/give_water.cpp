#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
typedef pair<int, int> position_t;
long long getDistance(position_t& pos1, position_t& pos2);
int main () {
    int nFlower = 0;
    position_t posA, posB;

    scanf("%d %d %d %d %d", &nFlower, &posA.first, &posA.second,
                            &posB.first, &posB.second);

    vector<pair<long long, long long> > distList(nFlower);

    for (int i = 0; i < nFlower; i++) {
        position_t flowerPos;
        scanf("%d %d", &flowerPos.first, &flowerPos.second);

        distList[i].first = getDistance(flowerPos, posA);
        distList[i].second = getDistance(flowerPos, posB);
    }

    /*
    long long result = numeric_limits<long long>::max();
    for (int i = 0; i < nFlower; i++) {
        long long &baseDist = distList[i].first;
        long long maxFromB = 0;
        for (int j = 0; j < nFlower; j++) {
            long long &compareDist = distList[j].first;
            if (baseDist < compareDist) {
                maxFromB = max(maxFromB, distList[j].second);
            }
        }
        result = min(result, baseDist + maxFromB);
    }

    for (int i = 0; i < nFlower; i++) {
        long long &baseDist = distList[i].second;
        long long maxFromA = 0;
        for (int j = 0; j < nFlower; j++) {
            long long &compareDist = distList[j].second;
            if (baseDist < compareDist) {
                maxFromA = max(maxFromA, distList[j].first);
            }
        }
        result = min(result, baseDist + maxFromA);
    }
    */

    long long result = numeric_limits<long long>::max();
    for (int i = 0; i < nFlower; i++) {
        long long &baseFromA = distList[i].first;
        long long &baseFromB = distList[i].second;
        long long maxFromA = 0;
        long long maxFromB = 0;
        for (int j = 0; j < nFlower; j++) {
            long long &compareFromA = distList[j].first;
            long long &compareFromB = distList[j].second;
            if (baseFromA < compareFromA) {
                maxFromB = max(maxFromB, compareFromB);
            }
            if (baseFromB < compareFromB) {
                maxFromA = max(maxFromA, compareFromA);
            }
        }
        result = min(result, baseFromA + maxFromB);
        result = min(result, baseFromB + maxFromA);
    }

    printf("%lld\n", result);

    return 0;
}
long long getDistance(position_t& pos1, position_t& pos2) {
    long long width = pos1.first - pos2.first;
    long long height = pos1.second - pos2.second;

    return width * width + height * height;
}
