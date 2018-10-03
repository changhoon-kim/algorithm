#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N = 0;
    scanf("%d", &N);

    vector<int> nums(N, 0);
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }

    sort(nums.begin(), nums.end());

    if (nums.size() > 1) {
        printf("%d\n", nums[0] * nums[nums.size()-1]);
    }
    else {
        printf("%d\n", nums[0] * nums[0]);
    }

    return 0;
}
