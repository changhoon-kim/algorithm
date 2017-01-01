#include <cstdio>
#include <vector>
using namespace std;
long long solution(vector<int>& chocolate);
long long count(vector<int>& chocolate, int start, int finish);
int getStraightZero(vector<int>& chocolate, int start, int finish);
int main() {
    int nBlock = 0;
    scanf("%d", &nBlock);

    vector<int> chocolate(nBlock, 0);
    for (int i = 0; i < nBlock; i++) {
        scanf("%d", &chocolate[i]);
    }

    printf("%lld\n", solution(chocolate));

    return 0;
}

long long solution(vector<int>& chocolate) {
    long long result = 1;
    int start = 0;
    int size = chocolate.size() - 1;
    for (int i = 0; i < size; i++) {
        if (chocolate[i] && chocolate[i] == chocolate[i+1]) {
            result *= count(chocolate, start, i);
            start = i + 1;
        }
    }
    result *= count(chocolate, start, size);

    return result;
}

long long count(vector<int>& chocolate, int start, int finish) {
    int left = 0, right = 0;
    for (left = start; left <= finish; left++) {
        if (chocolate[left]) {
            start = left;
            break;
        }
    }

    for (right = finish; right >= start; right--) {
        if (chocolate[right]) {
            finish = right;
            break;
        }
    }

    if (left > right) return 0;

    long long count = 1;
    for (int i = start + 1; i <= finish - 1; i++) {
        if (chocolate[i]) continue;
        int zeroCount = getStraightZero(chocolate, i, finish);
        count *= (zeroCount + 1);
        i += zeroCount;
    }

    return count;
}

int getStraightZero(vector<int>& chocolate, int start, int finish) {
    int count = 0;
    for (int i = start; i <= finish; i++) {
        if (chocolate[i] == 0) count++;
        else break;
    }

    return count;
}
