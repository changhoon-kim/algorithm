import pytest

class Papaer:
    def __init__(self, priority, location):
        self.priority = priority
        self.location = location

def solution(priorities, location):
    ps = sorted(priorities, reverse=True)
    papers = []
    for i, p in enumerate(priorities):
        papers.append(Papaer(p, i))

    answer = 0
    while True:
        top_paper = papers.pop(0)
        if top_paper.location == location and top_paper.priority >= ps[0]:
            return answer + 1

        if top_paper.priority < ps[0]:
            papers.append(top_paper)
        else:
            ps.pop(0)
            answer += 1
    
    return answer

@pytest.mark.parametrize('priorities, location, expected', [
    ([2, 1, 3, 2], 2, 1),
    ([1, 1, 9, 1, 1, 1], 0, 5),
])
def test_example(priorities, location, expected):
    assert expected == solution(priorities, location)