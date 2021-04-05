import pytest

def solution(progresses, speeds):
    jobs = len(progresses)
    st = []
    answer = []
    for i in range(jobs):
        progress = progresses[i]
        speed = speeds[i]

        remain_ratio = 100 - progress
        remain = remain_ratio // speed
        if remain_ratio % speed > 0:
            remain += 1

        if len(st) > 0 and st[0] < remain:
            answer.append(len(st))
            st = [remain]
        else:
            st.append(remain)

    if len(st) > 0:
        answer.append(len(st))

    return answer

@pytest.mark.parametrize('progresses, speeds, expected', [
    ([93, 30, 55], [1, 30, 5], [2, 1]),
    ([95, 90, 99, 99, 80, 99], [1, 1, 1, 1, 1, 1], [1, 3, 2]),
    ([40, 70, 60, 30], [1, 1, 1, 1], [3, 1])
])
def test_example(progresses, speeds, expected):
    assert expected == solution(progresses, speeds)