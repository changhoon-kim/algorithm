#include <cstdio>
#include <cstring>
#define MOD 123456789
using namespace std;

bool prime[10001];
int cache[10001];

int main(){
    int T, N, i, j, maxIdx;

    // make prime set
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (i = 2; i <= 100; i++){ // root 10000
        if (prime[i] == false)
            continue;
        for (j = 2*i; j <= 10000; j += i)
            prime[j] = false;
    }
    // end prime set

    N = 10000; // max input
    memset(cache, 0, (N+1)*sizeof(int));
    cache[0] = 1;
    maxIdx = 0;
    for (int i = 2; i <= N; i++){
        if (prime[i]){ // 2, 3, 5, 7, 11...
            maxIdx = (maxIdx+i <= N) ? maxIdx : N-i;
            for (int j = maxIdx; j >= 0; j--){
                if (cache[j] > 0) {
                    cache[j+i] = (cache[j+i] + cache[j]) % MOD;
                }
            }
            maxIdx = (maxIdx+i <= N) ? maxIdx+i : maxIdx;
        }
    }

    // get solution

    scanf("%d", &T);
    while (T--){
        scanf("%d", &N);
        printf("%d\n", cache[N]);
    }
    return 0;

    // solution end
}
