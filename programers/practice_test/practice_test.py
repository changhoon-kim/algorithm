import pytest

def solution(answers):
    check_map = {
        1: {
            'pattern': [1, 2, 3, 4, 5],
            'correct': 0,
            'index': 0
        },
        2: {
            'pattern': [2, 1, 2, 3, 2, 4, 2, 5],
            'correct': 0,
            'index': 0
        },
        3: {
            'pattern': [3, 3, 1, 1, 2, 2, 4, 4, 5, 5],
            'correct': 0,
            'index': 0
        }
    }

    for answer in answers:
        for _, v in check_map.items():
            if answer == v['pattern'][v['index']]:
                v['correct'] += 1

            v['index'] += 1
            v['index'] = v['index'] % len(v['pattern'])

    if check_map[1]['correct'] > check_map[2]['correct']:
        if check_map[3]['correct'] > check_map[1]['correct']:
            return [3]
        elif check_map[3]['correct'] < check_map[1]['correct']:
            return [1]
        else:
            return [1,3]
    elif check_map[1]['correct'] < check_map[2]['correct']:
        if check_map[2]['correct'] > check_map[3]['correct']:
            return [2]
        elif check_map[2]['correct'] < check_map[3]['correct']:
            return [3]
        else:
            return [2,3]
    else:
        if check_map[1]['correct'] > check_map[3]['correct']:
            return [1,2]
        elif check_map[1]['correct'] < check_map[3]['correct']:
            return [3]
        else:
            return [1,2,3]

@pytest.mark.parametrize('answers, expected', [
    ([1,2,3,4,5], [1]),
    ([1,3,2,4,2], [1,2,3])
])
def test_example(answers, expected):
    assert expected == solution(answers)