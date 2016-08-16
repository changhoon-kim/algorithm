#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
const int MAX = std::numeric_limits<int>::max();
int nCoin;
int change;
vector<int> coins;
void input();
int getMinCoins(int remainChange, int currentCoinIdx, int coinCount);
int main() {
    input();

    // 가지고 있는 동전 조합으로 거스름돈을 항상 만들 수 있다고 가정
    printf("%d\n", getMinCoins(change, nCoin - 1, 0));

    return 0;
}
void input() {
    scanf("%d", &nCoin);
    // coins 는 정렬된 상태로 입력된다고 가정
    coins = vector<int>(nCoin, 0);
    for(int i = 0; i < nCoin; i++) {
        scanf("%d", &coins[i]);
    }
    scanf("%d", &change);
}
int getMinCoins(int remainChange, int currentCoinIdx, int coinCount) {
    if(remainChange == 0) return coinCount;
    if(currentCoinIdx < 0) return MAX;
    int currentCoin = coins[currentCoinIdx];
    if(remainChange < currentCoin)
        return getMinCoins(remainChange, currentCoinIdx - 1, coinCount);

    return min(getMinCoins(remainChange, currentCoinIdx - 1, coinCount),
        getMinCoins(remainChange - currentCoin, currentCoinIdx, coinCount + 1));
}
