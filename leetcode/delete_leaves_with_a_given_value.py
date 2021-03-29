import pytest

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

def get_depth(root, curr_depth):
    if root is None:
        return 0

    left_depth = get_depth(root.left, curr_depth+1)
    right_depth = get_depth(root.right, curr_depth+1)

    return max([curr_depth, left_depth, right_depth])

def get_tree_node_size(root):
    if root is None:
        return 0

    depth = get_depth(root, 1)

    return 2 ** depth - 1

def insert_value(root, values, pos):
    if root is None:
        if pos < len(values):
            values[pos] = root
        return
    else:
        values[pos] = root.val

    insert_value(root.left, values, 2*pos+1)
    insert_value(root.right, values, 2*pos+2)

def convert_to_list(root):
    tree_node_size = get_tree_node_size(root)
    if tree_node_size == 0:
        return []

    values = [False] * tree_node_size

    insert_value(root, values, 0)

    ret = []
    for v in values:
        if v is False:
            continue

        ret.append(v)

    return ret

def test_convert_to_list():
    t = TreeNode()
    t.val = 1

    assert [1] == convert_to_list(t)

    r = TreeNode()
    r.val = 3
    t.right = r

    assert [1, None, 3] == convert_to_list(t)

    l = TreeNode()
    l.val = 2
    t.left = l

    assert [1, 2, 3] == convert_to_list(t)

def test_convert():
    target = [1,2,3,2,None,2,4]
    assert target == convert_to_list(convert_to_treenode(target))


class Solution:
    def remove(self, root: TreeNode, target: int) -> bool:
        if root is None:
            return True

        is_removed = self.remove(root.left, target)
        if is_removed:
            root.left = None

        is_removed = self.remove(root.right, target)
        if is_removed:
            root.right = None

        if root.left is None and root.right is None and root.val == target:
            return True

        return False

    def removeLeafNodes(self, root: TreeNode, target: int) -> TreeNode:
        if self.remove(root, target):
            return None

        return root


@pytest.mark.parametrize('input, target, output', [
    ([1,2,3,2,None,2,4], 2, [1,None,3,None,4]),
    ([1,3,3,3,2], 3, [1,3,None,None,2]),
    ([1,2,None,2,None,2], 2, [1]),
    ([1,1,1], 1, []),
    ([1,2,3], 1, [1,2,3])
])
def test_example(input, target, output):
    t = convert_to_treenode(input)
    s = Solution()
    expected = convert_to_list(s.removeLeafNodes(t, target))
    print(expected)
    assert output == expected