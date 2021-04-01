import pytest

def solution(numbers):
    str_numers = []
    for number in numbers:
        str_numers.append(str(number))

    str_numers.sort(key=lambda x:x*3, reverse=True)

    return str(int(''.join(str_numers)))

@pytest.mark.parametrize('numbers, expected', [
    ([6, 10, 2], '6210'),
    ([3, 30, 34, 5, 9], '9534330'),
    ([3, 30, 30, 300, 301, 304], '33043030301300'),
])
def test_example(numbers, expected):
    assert expected == solution(numbers)