length = int(input())
candidates = input()

count = [0]*length

set_start = False
for i, candidate in enumerate(candidates):
    if set_start == False:
        if candidate == '0':
            continue

    next1 = i + 1
    next2 = i + 2

    if next1 < length and candidates[next1] != '0':
        if set_start == False:
            count[next1] = 1
        else:
            count[next1] += count[i]

    if next2 < length and candidates[next2] != '0':
        if set_start == False:
            count[next2] = 1
        else:
            count[next2] += count[i]

    set_start = True

print(count[-1])
