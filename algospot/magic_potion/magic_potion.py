import sys, math

def solution(item_count, needs, pasts):
    overflow = False
    ratios = []
    for i in range(item_count):
        ratio = float(pasts[i]) / needs[i]
        ratios.append((ratio, i))

        if ratio > 1:
            overflow = True

    if not overflow:
        answer = []
        for i in range(item_count):
            answer.append(str(needs[i] - pasts[i]))
        return ' '.join(answer)

    adds = []
    sorted_ratio = sorted(ratios, key=lambda x: x[0], reverse=True)
    ratio, index = sorted_ratio[0]

    for i in range(item_count):
        target = needs[i] * ratio
        if target - int(target) > 0:
            adds = []
            ratio = math.ceil(ratio)

            for j in range(item_count):
                target = needs[j] * ratio
                add = str(int(target) - pasts[j])
                adds.append(add)
            
            return ' '.join(adds)

        else:
            add = str(int(target) - pasts[i])
            adds.append(add)

    return ' '.join(adds)


if __name__ == '__main__':
    case_count = int(sys.stdin.readline())
    for i in range(case_count):
        item_count = int(sys.stdin.readline())
        needs = list(map(int, sys.stdin.readline().split()))
        pasts = list(map(int, sys.stdin.readline().split()))

        answer = solution(item_count, needs, pasts)
        print(answer)