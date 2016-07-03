#include <cstdio>
#include <vector>
#include <string>
using namespace std;
int32_t directionRow[] = {1, 1,  0, -1, -1, -1, 0, 1};
int32_t directionCol[] = {0, -1, -1, -1, 0, 1, 1, 1};
bool isExistWord(vector<string>& board, string& word, int32_t row, int32_t col, int32_t index);
bool outOfBoard(int32_t row, int32_t col);
int main() {
    int32_t nCase = 0;

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
        int32_t nWord = 0;
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
            if(isExistWord(board, words[i], -1, -1, 0)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
}
bool isExistWord(vector<string>& board, string& word, int32_t row, int32_t col, int32_t index) {
    if(index >= word.size()) return true;

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

    for(int i = 0; i < 8; i++) {
        int32_t nextRow = row + directionRow[i];
        int32_t nextCol = col + directionCol[i];
        if(outOfBoard(nextRow, nextCol)) continue;
        if(board[nextRow][nextCol] == word[index]) {
            if(isExistWord(board, word, nextRow, nextCol, index + 1))
                return true;
        }
    }

    return false;
}
bool outOfBoard(int32_t row, int32_t col) {
    if(row < 0 || col < 0) return true;
    if(row > 4 || col > 4) return true;
    return false;
}
