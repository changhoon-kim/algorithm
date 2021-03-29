#include <string>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

bool solution(vector<string> phone_book) {
    set<string> checkSet{phone_book.begin(), phone_book.end()};
    for (auto phone : phone_book) {
        string prefix;
        for (auto num : phone) {
            prefix += num;

            if (prefix == phone) {
                continue;
            }

            if (checkSet.count(prefix)) {
                return false;
            }
        }
    }
    return true;
}

void testExample() {
    assert(solution({"119", "97674223", "1195524421"}) == false);
    assert(solution({"123","456","789"}) == true);
    assert(solution({"12","123","1235","567","88"}) == false);
}

int main() {
    testExample();

    return 0;
}