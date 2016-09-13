#include <iostream>
#include <string>
using namespace std;
string reverse(string &quadTree, int *index);
int main() {
    int nCase = 0;
    cin >> nCase;

    while(nCase--) {
        string quadTreeStr;
        cin >> quadTreeStr;

        int index = 0;
        cout << reverse(quadTreeStr, &index) << endl;
    }

    return 0;
}
string reverse(string &quadTree, int *index) {
    int currIndex = *index;
    (*index)++;
    if(quadTree[currIndex] == 'b' || quadTree[currIndex] == 'w') {
        return quadTree.substr(currIndex, 1);
    }

    string leftTop = reverse(quadTree, index);
    string rightTop = reverse(quadTree, index);
    string leftBottom = reverse(quadTree, index);
    string rightBottom = reverse(quadTree, index);

    return "x" + leftBottom + rightBottom + leftTop + rightTop;
}
