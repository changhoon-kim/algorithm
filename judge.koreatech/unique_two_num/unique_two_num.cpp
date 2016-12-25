#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int nCase = 0;
    scanf("%d", &nCase);

    while(nCase--) {
        int nNum = 0;
        scanf("%d", &nNum);

        map<int, int> pairs;
        for (int i = 0; i < nNum; i++) {
            int num = 0;
            scanf("%d", &num);
            pairs[num]++;
        }

        vector<int> solo;
        map<int, int>::iterator iter = pairs.begin();
        for ( ; iter != pairs.end(); iter++) {
            const int &num = iter->first;
            const int &count = iter->second;
            if (count % 2) solo.push_back(num);
        }

        printf("%d %d\n", min(solo[0], solo[1]), max(solo[0], solo[1]));
    }

    return 0;
}

