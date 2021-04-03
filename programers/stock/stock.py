import pytest

def solution(prices):
    answer = [0] * len(prices)
    s = []
    for i, price in enumerate(prices):
        while len(s) > 0 and prices[s[-1]] > prices[i]:
            answer[s[-1]] = i - s[-1]
            s.pop()

        s.append(i)

    while len(s) > 0:
        answer[s[-1]] = len(prices) - s[-1] - 1
        s.pop()

    return answer

@pytest.mark.parametrize('prices, expected', [
    ([1, 2, 3, 2, 3], [4, 3, 1, 1, 0]),
])
def test_example(prices, expected):
    assert expected == solution(prices)