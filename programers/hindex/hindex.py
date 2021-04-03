import pytest

def solution(citations):
    citations.sort(reverse=True)

    answer = 0
    for i, count in enumerate(citations):
        hindex = i + 1
        if hindex > count:
            break
        
        answer = hindex

    return answer

@pytest.mark.parametrize('citations, expected', [
    ([3, 0, 6, 1, 5], 3),
    ([1, 7, 0, 1, 6, 4], 3),
    ([10, 50, 100], 3)
])
def test_example(citations, expected):
    assert expected == solution(citations)