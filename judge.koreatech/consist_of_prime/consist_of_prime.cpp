#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
void preProcess();
void setPrime();
void setCache();
const int INPUT_MAX = 10000;
const int MOD = 123456789;
vector<bool> isPrime(INPUT_MAX+ 1, true);
vector<int> cache(INPUT_MAX + 1, 0);
int main() {
    preProcess();

    int nCase = 0;
    scanf("%d", &nCase);

    while(nCase--) {
        int num = 0;
        scanf("%d", &num);

        printf("%d\n", cache[num]);
    }

    return 0;
}
void preProcess() {
    setPrime();
    setCache();
}
void setPrime() {
    int maxRange = sqrt(INPUT_MAX);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= maxRange; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= INPUT_MAX; j += i) {
            isPrime[j] = false;
        }
    }
}
void setCache() {
    int start = 0;
    cache[0] = 1;
    for (int currNum = 2; currNum <= INPUT_MAX; currNum++) {
        if (isPrime[currNum]) {
            start = (start + currNum) <= INPUT_MAX ?
                    start : INPUT_MAX - currNum;
            for (int num = start; num >= 0; num--) {
                if (cache[num]) {
                    cache[currNum + num] =
                        (cache[currNum + num] + cache[num]) % MOD;
                }
            }
            // num은 start에서 시작하고, currNum + num 에
            // 접근하기 때문에 start 의 최댓값은 start + currNum
            start = (start + currNum) <= INPUT_MAX ?
                    start + currNum : start;
        }
    }
}
