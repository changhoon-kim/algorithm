import pytest
from typing import List

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        pos = len(nums)
        for i, num in enumerate(nums):
            if num >= target:
                pos = i
                break

        return pos


@pytest.mark.parametrize('nums, target, expected', [
    ([1,3,5,6], 5, 2),
    ([1,3,5,6], 2, 1),
    ([1,3,5,6], 7, 4),
    ([1,3,5,6], 0, 0),
    ([1], 0, 0),
])
def test_example(nums, target, expected):
    s = Solution()
    assert expected == s.searchInsert(nums, target)