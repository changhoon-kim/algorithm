import pytest

def solution(clothes):
    closet_map = {}
    for row in clothes:
        name = row[0]
        type = row[1]
        if not type in closet_map:
            closet_map[type] = [None]
        closet_map[type].append(name)

    answer = 1
    for c in closet_map:
        answer *= len(closet_map[c])

    answer -= 1

    return answer

@pytest.mark.parametrize('clothes, expected', [
    ([["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]], 5),
    ([["crowmask", "face"], ["bluesunglasses", "face"], ["smoky_makeup", "face"]], 3),
])
def test_example(clothes, expected):
    assert expected == solution(clothes)