# -*- coding: utf-8 -*-
def pairing(row, num_student):
    if row >= num_student:
        return 1

    if paired[row] is True:
        return pairing(row + 1, num_student)

    result = 0
    for i in range(0, num_student):
        if paired[i] is False and pair_matrix[row][i] is True:
            paired[row] = True
            paired[i] = True
            result = result + pairing(row + 1, num_student)
            paired[row] = False
            paired[i] = False

    return result

def init_pair_matrix_with_paired(num_student, pair_list):
    global pair_matrix, paired
    pair_matrix = []
    paired = []

    for i in range(0, num_student):
        line = []
        for j in range(0, num_student):
            line.append(False)
        pair_matrix.append(line)
        paired.append(False)

    for i in range(0, len(pair_list), 2):
        pair_matrix[pair_list[i]][pair_list[i+1]] = True
        pair_matrix[pair_list[i+1]][pair_list[i]] = True

if __name__ == "__main__":
    num_case = int(raw_input())
    while num_case > 0:
        num_student, num_pair = raw_input().strip().split()
        num_student = int(num_student)
        num_pair = int(num_pair)
        pair_list = raw_input().strip().split()
        pair_list = [int(i) for i in pair_list]
        init_pair_matrix_with_paired(num_student, pair_list)

        # solution
        # 1. 현재 행의  친구가 될 수 있는 번호를 matrix 에서 탐색
        # 2. 가능한 친구가 있으면 친구가 되었음을 표시
        # 3. 친구가 되었음을 확인하며 다음 번호에 대해서 계속해서 탐색
        # 4. row 가 num_student 가 되었으면 1을 반환
        # 5. 1~4 를 재귀 호출을 통해서 반복
        result = 0
        for i in range(0, num_student):
            if pair_matrix[0][i] is True:
                paired[0] = True
                paired[i] = True
                result = result + pairing(1, num_student)
                paired[0] = False
                paired[i] = False

        print result

        num_case = num_case - 1
