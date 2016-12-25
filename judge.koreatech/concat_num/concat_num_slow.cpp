#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
void preProcess(vector<int> &nums);
void pushEachNumber(vector<int> &nums, int num);
vector<int> getSplitNum(int num);
int main() {
    vector<int> nums;
    nums.reserve(5000);
    preProcess(nums);

    int nCase = 0;
    scanf("%d", &nCase);

    while(nCase--) {
        int pos = 0;
        scanf("%d", &pos);

        printf("%d\n", nums[pos-1]);
    }

    return 0;
}
void preProcess(vector<int> &nums) {
    for (int i = 1; i < 10000; i++) {
        pushEachNumber(nums, i);
    }
}
void pushEachNumber(vector<int> &nums, int num) {
    vector<int> splitedNum = getSplitNum(num);
    int size = splitedNum.size();
    for (int i = size - 1; i >= 0; i--) {
        nums.push_back(splitedNum[i]);
    }
}
vector<int> getSplitNum(int num) {
    vector<int> splitedNum;
    while (num) {
        splitedNum.push_back(num % 10);
        num /= 10;
    }
    return splitedNum;
}
