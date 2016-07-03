#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int directionRow[] = {1, 1,  0, -1, -1, -1, 0, 1};
int directionCol[] = {0, -1, -1, -1, 0, 1, 1, 1};
bool isExistWord(vector<string>& board, string& word, int row, int col, int index);
bool inBoard(int row, int col);
int cache[10][5][5];
int main() {
    int nCase = 0;

    scanf("%d", &nCase);

    while(nCase--) {
        vector<string> board(5);

        // input board
        for(int i = 0; i < 5; i++) {
            char buf[6];
            scanf("%s", buf);
            board[i] = buf;
        }

        // input known words
        int nWord = 0;
        scanf("%d", &nWord);
        vector<string> words(nWord);
        for(int i = 0; i < nWord; i++) {
            char buf[11];
            scanf("%s", buf);
            words[i] = buf;
        }


        // solution
        // 1. 단어를 찾는 함수를 호출
        // 2. 해당 함수에서는 해당 단어의 첫 글자가 board 에 존재하는지 탐색
        // 3. 있으면 팔방 검사를 하며 단어의 해당 문자가 있는지 탐색
        // 4. 탐색 중 해당 문자가 없으면 false 모두 찾으면 true return
        // 5. return 결과에 따라 'YES' or 'NO' 출력
        // 6. 알고 있는 단어에 대해 1~5 과정을 반복
        for(int i = 0; i < nWord; i++) {
            memset(cache, -1, sizeof(cache));
            if(isExistWord(board, words[i], -1, -1, 0)) {
                printf("%s YES\n", words[i].c_str());
            } else {
                printf("%s NO\n", words[i].c_str());
            }
        }
    }

    return 0;
}
bool isExistWord(vector<string>& board, string& word, int row, int col, int index) {
    if(index >= (int)word.size()) return true;

    if(row == -1) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(board[i][j] == word[index]) {
                    if(isExistWord(board, word, i, j, index + 1))
                        return true;
                }
            }
        }

        return false;
    }

    int& result = cache[index][row][col];
    if(result != -1) return result;
    result = 0;
    for(int i = 0; i < 8; i++) {
        int nextRow = row + directionRow[i];
        int nextCol = col + directionCol[i];
        if(inBoard(nextRow, nextCol) && board[nextRow][nextCol] == word[index]) {
            result = result | isExistWord(board, word, nextRow, nextCol, index + 1);
        }
    }

    return result;
}
bool inBoard(int row, int col) {
    if(row < 0 || col < 0) return false;
    if(row > 4 || col > 4) return false;
    return true;
}
