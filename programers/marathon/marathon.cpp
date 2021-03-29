#include <string>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> countMap;
    for (const string& c : completion) {
        countMap[c]++;
    }

    for (const string& p : participant) {
        if (countMap.find(p) == countMap.end()) {
            return p;
        }

        countMap[p]--;

        if (countMap[p] == 0) {
            countMap.erase(p);
        }
    }

    return "";
}

void testExample() {
    assert("leo" == solution({"leo", "kiki", "eden"}, {"eden", "kiki"}));
    assert("vinko" == solution({"marina", "josipa", "nikola", "vinko", "filipa"}, {"josipa", "filipa", "marina", "nikola"}));
    assert("mislav" == solution({"mislav", "stanko", "mislav", "ana"}, {"stanko", "ana", "mislav"}));
}

int main() {
    testExample();
    return 0;
}