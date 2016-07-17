block = [[[1,0], [0,1]], [[1,0], [1,-1]], [[1,0], [1,1]], [[1,1], [0,1]]]
EMPTY_POINT = 0
NOT_EMPTY_POINT = 1

def can_put(row, col, index):
    for i in range(0, 2):
        check_row = row + block[index][i][0]
        check_col = col + block[index][i][1]
        if check_row >= height or check_col >= width:
            return False
        if board[check_row][check_col] != EMPTY_POINT: # '.'
            return False

    return True

def put(row, col, index):
    for i in range(0, 2):
        put_row = row + block[index][i][0]
        put_col = col + block[index][i][1]
        board[put_row][put_col] = NOT_EMPTY_POINT # '#'

def unput(row, col, index):
    for i in range(0, 2):
        unput_row = row + block[index][i][0]
        unput_col = col + block[index][i][1]
        board[unput_row][unput_col] = EMPTY_POINT # '.'

def count_cover(row, col):
    if col >= width:
        return count_cover(row + 1, 0)

    if row >= height:
        return 1

    if board[row][col] != EMPTY_POINT: # '.'
        return count_cover(row, col + 1)

    result = 0
    for i in range(len(block)):
        if can_put(row, col, i):
            put(row, col, i)
            result = result + count_cover(row, col + 1)
            unput(row, col, i)

    return result

if __name__ == "__main__":
    num_case = int(raw_input())

    global board, height, width
    while num_case > 0:
        height, width = raw_input().strip().split()
        height = int(height)
        width = int(width)
        board = []
        for i in range(0, height):
            line = []
            for char in raw_input():
                if char == '.':
                    line.append(EMPTY_POINT)
                else:
                    line.append(NOT_EMPTY_POINT)
            board.append(line)

        print count_cover(0, 0)

        num_case = num_case - 1
