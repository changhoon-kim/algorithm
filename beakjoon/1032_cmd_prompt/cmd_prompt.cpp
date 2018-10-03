#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main () {
    int N = 0;
    cin >> N;

    vector<string> files(N);

    for (int i = 0; i < N; i++) {
        cin >> files[i];
    }

    string result;
    int nameLength = files[0].size();
    for (int i = 0; i < nameLength; i++) {
        bool allSame = true;
        char checkChar = files[0][i];
        for (int j = 1; j < N; j++) {
            if (files[j][i] != checkChar) {
                allSame = false;
                break;
            }
        }
        if (allSame) {
            result += checkChar;
        }
        else {
            result += "?";
        }
    }

    cout << result << endl;

    return 0;
}
