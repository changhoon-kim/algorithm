import pytest

def solution(phone_book):
    last_index = len(phone_book)-1
    phone_book.sort()
    for i in range(last_index):
        if phone_book[i+1].startswith(phone_book[i]):
            return False

    return True

@pytest.mark.parametrize('phone_book, expected', [
    (['119', '97674223', '1195524421'], False),
    (['123','456','789'], True),
    (['12','123','1235','567','88'], False)
])
def test_example(phone_book, expected):
    assert expected == solution(phone_book)
