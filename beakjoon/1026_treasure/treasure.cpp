#include <vector>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
    int N = 0;
    scanf("%d", &N);

    vector<int> A = vector<int>(N, 0);
    vector<int> B = vector<int>(N, 0);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());

    int S = 0;
    for (int i = 0; i < N; i++) {
        S = S + A[i] * B[i];
    }

    printf("%d", S);

    return 0;
}
