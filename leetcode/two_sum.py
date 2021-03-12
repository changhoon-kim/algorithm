import pytest
from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ret = list()
        pair = dict()
        for i, num in enumerate(nums):
            diff = target - num
            if diff in pair:
                ret = [pair[diff], i]
                break

            pair[num] = i

        return ret

@pytest.mark.parametrize('nums, target, expected', [
    ([2,7,11,15], 9, [0, 1]),
    ([3,2,4], 6, [1, 2]),
    ([3,3], 6, [0, 1]),
])
def test_example(nums, target, expected):
    s = Solution()
    assert expected == s.twoSum(nums, target)