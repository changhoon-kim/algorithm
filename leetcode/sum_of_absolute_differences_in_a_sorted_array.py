from typing import List

class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        count = len(nums)
        right_sum = sum(nums)
        left_sum = 0
        result = []
        for i, num in enumerate(nums):
            r = (right_sum - num * (count - i)) + ((num * i) - left_sum)
            result.append(r)

            left_sum += num
            right_sum -= num

        return result

def test_example():
    nums = [2,3,5]
    s = Solution()
    assert [4,3,5] == s.getSumAbsoluteDifferences(nums)

def test_my_example():
    nums = [1,2,5,8]
    s = Solution()
    assert [12,10,10,16] == s.getSumAbsoluteDifferences(nums)