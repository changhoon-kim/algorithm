import pytest
import heapq

def solution(scoville, K):
    heap = []
    for s in scoville:
        heapq.heappush(heap, s)

    answer = 0
    while heap[0] < K:
        if len(heap) <= 1:
            return -1

        first = heapq.heappop(heap)
        second = heapq.heappop(heap)
        new_scoville = first + second * 2
        heapq.heappush(heap, new_scoville)
        answer += 1

    return answer

@pytest.mark.parametrize('scoville, k, expected', [
    ([1, 2, 3, 9, 10, 12], 7, 2),
    ([1, 2, 3, 9, 10, 12], 110, -1),
])
def test_example(scoville, k, expected):
    assert expected == solution(scoville, k)