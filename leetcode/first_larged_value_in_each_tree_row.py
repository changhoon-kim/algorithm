import pytest
from typing import List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def add_treenode(root, values, curr_index):
    if curr_index >= len(values):
        return

    root.val = values[curr_index]

    left_index = curr_index * 2 + 1
    if left_index < len(values) and values[left_index]:
        left = TreeNode()
        add_treenode(left, values, left_index)
        root.left = left

    right_index = left_index + 1
    if right_index < len(values) and values[right_index]:
        right = TreeNode()
        add_treenode(right, values, right_index)
        root.right = right

def convert_to_treenode(values):
    size = len(values)
    if size == 0:
        return None

    t = TreeNode()
    add_treenode(t, values, 0)

    return t

def test_converting_happy():
    input = [1,2,3,4,5,6,7]
    t = convert_to_treenode(input)

    assert 1 == t.val
    assert 2 == t.left.val
    assert 3 == t.right.val

    assert 4 == t.left.left.val
    assert 5 == t.left.right.val

    assert 6 == t.right.left.val
    assert 7 == t.right.right.val

def test_has_none():
    input = [1,2,None,4,5]
    t = convert_to_treenode(input)

    assert 1 == t.val
    assert 2 == t.left.val
    assert None == t.right

    assert 4 == t.left.left.val
    assert 5 == t.left.right.val

def test_empty():
    input = []
    t = convert_to_treenode(input)
    assert None == t

class Solution:
    def _update(self, key, new_value):
        if key in self.depth_max_value_dict:
            self.depth_max_value_dict[key] = max(new_value, self.depth_max_value_dict[key])
        else:
            self.depth_max_value_dict[key] = new_value

    def _next(self, root, current_depth):
        current_depth += 1
        if root.left:
            self._update(current_depth, root.left.val)
            self._next(root.left, current_depth)

        if root.right:
            self._update(current_depth, root.right.val)
            self._next(root.right, current_depth)

    def _convert_to_list(self):
        ret = [None] * len(self.depth_max_value_dict)
        for depth, value in self.depth_max_value_dict.items():
            ret[depth] = value

        return ret

    def largestValues(self, root: TreeNode) -> List[int]:
        if root is None:
            return []

        current_depth = 0
        self.depth_max_value_dict = {current_depth: root.val}
        self._next(root, current_depth)

        return self._convert_to_list()

@pytest.mark.parametrize('input, expected', [
    ([1,3,2,5,3,None,9], [1,3,9]),
    ([1,2,3], [1,3]),
    ([1], [1]),
    ([1,None,2], [1,2]),
    ([], []),
])
def test_example(input, expected):
    t = convert_to_treenode(input)
    s = Solution()
    assert expected == s.largestValues(t)