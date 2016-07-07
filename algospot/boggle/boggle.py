def init_cache():
    global cache
    cache = []
    for i in range(0, 10):
        row_line = []
        for j in range(0, 5):
            col_line = []
            for k in range(0, 5):
                col_line.append(-1)
            row_line.append(col_line)
        cache.append(row_line)


def has_word_recursion(word, row, col, idx):
    if len(word) == idx:
        return True

    if row < 0 or col < 0:
        return False
    if row > 4 or col > 4:
        return False

    if cache[idx][row][col] != -1:
        return cache[idx][row][col]

    if board[row][col] == word[idx]:
        cache[idx][row][col] = \
             has_word_recursion(word, row + 1, col, idx + 1) or \
             has_word_recursion(word, row + 1, col - 1, idx + 1) or \
             has_word_recursion(word, row, col - 1, idx + 1) or \
             has_word_recursion(word, row - 1, col - 1, idx + 1) or \
             has_word_recursion(word, row - 1, col, idx + 1) or \
             has_word_recursion(word, row - 1, col + 1, idx + 1) or \
             has_word_recursion(word, row, col + 1, idx + 1) or \
             has_word_recursion(word, row + 1, col + 1, idx + 1)
    else:
        cache[idx][row][col] = False

    return cache[idx][row][col]

def has_word(word):
    if len(word) == 1:
        return True

    for i in range(0, 5):
        for j in range(0, 5):
            if has_word_recursion(word, i, j, 0):
                return True

    return False

if __name__ == "__main__":
    nCase = int(raw_input())

    while nCase > 0:
        global board
        board = []
        for i in range(0, 5):
            board.append(raw_input())

        nWord = int(raw_input())
        while(nWord > 0):
            init_cache()
            word = raw_input()
            if has_word(word):
                print word, "YES"
            else:
                print word, "NO"
            nWord = nWord - 1
        nCase = nCase - 1
