import pytest

def solution(array, commands):
    answer = []
    for command in commands:
        sub = array[command[0]-1:command[1]]
        sub.sort()
        answer.append(sub[command[2]-1])

    return answer

@pytest.mark.parametrize('arr, commands, expected', [
    ([1,5,2,6,3,7,4], [[2,5,3], [4,4,1], [1,7,3]], [5,6,3]),
])
def test_example(arr, commands, expected):
    assert expected == solution(arr, commands)