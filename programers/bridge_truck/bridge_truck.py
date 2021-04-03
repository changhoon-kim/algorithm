import pytest

class Truck:
    def __init__(self, elapsed, weight):
        self.elapsed = elapsed
        self.weight = weight

def solution(bridge_length, weight, truck_weights):
    elapsed = 0
    current_weight = 0
    remains = []
    while len(truck_weights) > 0:
        elapsed += 1

        if len(remains) > 0 and remains[0].elapsed == elapsed:
            current_weight -= remains[0].weight
            remains.pop(0)

        next_weight = truck_weights[0]
        if current_weight + next_weight <= weight:
            truck_weights.pop(0)
            current_weight += next_weight
            remains.append(Truck(elapsed + bridge_length, next_weight))
    
    if len(remains) > 0:
        return remains[-1].elapsed

    return elapsed

@pytest.mark.parametrize('bridge_length, weight, truck_weights, expected', [
    (2, 10, [7,4,5,6], 8),
    (100, 100, [10], 101),
    (100, 100, [10,10,10,10,10,10,10,10,10,10], 110),
    (5, 10, [7,8], 11)
])
def test_example(bridge_length, weight, truck_weights, expected):
    assert expected == solution(bridge_length, weight, truck_weights)