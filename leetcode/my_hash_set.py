class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = dict()

    def add(self, key: int) -> None:
        self.data[key] = True
        return None

    def remove(self, key: int) -> None:
        if key in self.data:
            self.data.pop(key)
        return None

    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        return self.data.get(key, False)


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)

def add(my_hash_set, value):
    return my_hash_set.add(value)

def contains(my_hash_set, value):
    return my_hash_set.contains(value)

def remove(my_hash_set, value):
    return my_hash_set.remove(value)

command_map = {
    'add': add,
    'contains': contains,
    'remove': remove
}

def test_example():
    commands = ['MyHashSet', 'add', 'add', 'contains', 'contains', 'add', 'contains', 'remove', 'contains']
    values = [[], [1], [2], [1], [3], [2], [2], [2], [2]]

    result = [None]
    my = MyHashSet()
    for i, command in enumerate(commands):
        if i == 0:
            continue

        value = values[i][0]
        result.append(command_map[command](my, value))

    expected = [None, None, None, True, False, None, True, None, False]

    assert expected == result