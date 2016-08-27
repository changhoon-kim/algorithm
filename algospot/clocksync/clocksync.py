switch_list = [
    [0, 1, 2],
    [3, 7, 9, 11],
    [4, 10, 14, 15],
    [0, 4, 5, 6, 7],
    [6, 7, 8, 10, 12],
    [0, 2, 14, 15],
    [3, 14, 15],
    [4, 5, 7, 14, 15],
    [1, 2, 3, 4, 5],
    [3, 4, 5, 9, 13]
]

MAX_COUNT = 31

def is_all_sync(clock_list):
    for clock in clock_list:
        if clock != 12:
            return False
    return True

def click_switch(switch, clock_list):
    for clock_num in switch_list[switch]:
        clock_list[clock_num] = clock_list[clock_num] + 3
        if clock_list[clock_num] == 15:
            clock_list[clock_num] = 3

def can_finish(switch):
    remain_switchs = set()
    for i in range(switch, len(switch_list)):
        remain_switchs = remain_switchs.union(set(switch_list[i]))

    for i in range(0, len(clock_list)):
        if not i in remain_switchs and clock_list[i] != 12:
            return False
    return True

def sync(count, switch, clock_list):
    if not can_finish(switch):
        return MAX_COUNT

    if switch >= 10:
        if is_all_sync(clock_list):
            return count
        else:
            return MAX_COUNT

    result = MAX_COUNT
    for i in range(0, 4):
        result = min(sync(count + i, switch + 1, clock_list), result)
        click_switch(switch, clock_list)

    return result

num_case = int(raw_input())

while num_case > 0:
    clock_list = raw_input().split()
    clock_list =[int(i) for i in clock_list]

    count = sync(0, 0, clock_list)
    if count < MAX_COUNT:
        print count
    else:
        print -1

    num_case = num_case - 1
