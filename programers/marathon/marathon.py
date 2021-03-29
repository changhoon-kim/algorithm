import pytest
from collections import defaultdict

def solution(participant, completion):
    comp_count_dict = defaultdict(int)
    for c in completion:
        comp_count_dict[c] += 1

    for p in participant:
        if not p in comp_count_dict:
            return p

        comp_count_dict[p] -= 1

        if comp_count_dict[p] == 0:
            comp_count_dict.pop(p)

    return ''

@pytest.mark.parametrize('participant, completion, expected', [
    (['leo', 'kiki', 'eden'], ['eden', 'kiki'], 'leo'),
    (['marina', 'josipa', 'nikola', 'vinko', 'filipa'], ['josipa', 'filipa', 'marina', 'nikola'], 'vinko'),
    (['mislav', 'stanko', 'mislav', 'ana'], ['stanko', 'ana', 'mislav'], 'mislav'),
])
def test_example(participant, completion, expected):
    assert expected == solution(participant, completion)