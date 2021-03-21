map_n_m = input().split()
n = int(map_n_m[0])
m = int(map_n_m[1])

cloth_info = []
count_info = []
while m:
    line = input().split()
    cloth_rows = []
    count_rows = []
    for cloth in line:
        cloth = int(cloth)
        cloth_rows.append(cloth)
        count_rows.append(cloth)

    cloth_info.append(cloth_rows)
    count_info.append(count_rows)
    m -= 1
m = len(cloth_info)

def is_valid_pos(row, col):
    if row < m and col < n:
        return True

    return False

def search(row, col):
    curr_cloth = count_info[row][col]

    rows = [row+1, row]
    cols = [col, col+1]

    for i in range(2):
        next_row = rows[i]
        next_col = cols[i]

        if not is_valid_pos(next_row, next_col):
            continue

        next_colth = cloth_info[next_row][next_col]

        count_info[next_row][next_col] = max(count_info[next_row][next_col], curr_cloth + next_colth)

    for i in range(2):
        next_row = rows[i]
        next_col = cols[i]

        if not is_valid_pos(next_row, next_col):
            continue

        search(next_row, next_col)

search(0, 0)
print(count_info[m-1][n-1])
