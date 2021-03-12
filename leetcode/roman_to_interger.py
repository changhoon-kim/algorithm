import pytest

class Solution:
    def romanToInt(self, s: str) -> int:
        char_value_map = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000,
        }

        sum = 0
        last_index = len(s) - 1
        for i, c in enumerate(s):
            num_value = char_value_map[c]
            sub = False

            if i < last_index:
                next_char = s[i+1]
                if c == 'I':
                    if next_char == 'V' or next_char == 'X':
                        sub = True
                elif c == 'X':
                    if next_char == 'L' or next_char == 'C':
                        sub = True
                elif c == 'C':
                    if next_char == 'D' or next_char == 'M':
                        sub = True

            if sub:
                sum -= num_value
            else:
                sum += num_value

        return sum

@pytest.mark.parametrize('rom, expected', [
    ('III', 3),
    ('IV', 4),
    ('IX', 9),
    ('LVIII', 58),
    ('MCMXCIV', 1994),
])
def test_example(rom, expected):
    s = Solution()
    assert expected == s.romanToInt(rom)