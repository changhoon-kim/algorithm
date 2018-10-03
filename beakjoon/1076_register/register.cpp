#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
map<string, map<int, int> > registerInfos;
void preProcess();
int main() {
    preProcess();

    string first, second, third;
    cin >> first >> second >> third;

    cout << (long long)(registerInfos[first][1] * 10 + registerInfos[second][2]) * registerInfos[third][3] << endl;

    return 0;
}
void preProcess() {
    vector<string> colors = {"black", "brown", "red", "orange", "yellow",
                             "green", "blue", "violet", "grey", "white"};
    int value = 1;

    for (int i = 0; i < 10; i++) {
        registerInfos[colors[i]][1] = i;
        registerInfos[colors[i]][2] = i;
        registerInfos[colors[i]][3] = value;
        value *= 10;
    }
}
