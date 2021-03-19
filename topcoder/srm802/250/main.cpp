#include <string>
#include <cassert>
#include <map>
#include <iostream>

using namespace std;

class BallotCounting
{
public:
    int count(string votes)
    {
        int total = votes.size();
        int half_over = (total / 2) + 1;
        int curr_count = 0;
        map<char, int> voteCountingMap;
        for (const char vote : votes)
        {
            voteCountingMap[vote] += 1;
            curr_count++;

            if (voteCountingMap[vote] >= half_over)
            {
                break;
            }
        }

        return curr_count;
    }
};

void testExample()
{
    BallotCounting bc;

    assert(bc.count("AAAAABBBBB") == 10);
    assert(bc.count("AAAAABBBBA") == 10);
    assert(bc.count("AAAAA") == 3);
    assert(bc.count("AAAAAA") == 4);
    assert(bc.count("AABAABAAB") == 7);
    assert(bc.count("BABABBB") == 6);
}

int main()
{
    testExample();

    cout << "SUCCESS" << endl;

    return 0;
}
