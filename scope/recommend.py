class Content:
    def __init__(self, view, type, priority, row, col):
        self.view = view
        self.type = type
        self.priority = priority
        self.row = row
        self.col = col

    def __lt__(self, other):
        if float(self.priority) > float(other.priority):
            return True
        elif float(self.priority) < float(other.priority):
            return False
        else:
            if self.row < other.row:
                return True
            elif self.row > other.row:
                return False
            else:
                if self.col < other.col:
                    return True
                else:
                    return False

priority_list = input().split()
type_priority_map = {
    'A': priority_list[0],
    'B': priority_list[1],
    'C': priority_list[2],
    'D': priority_list[3],
    'E': priority_list[4],
}

n_m = input().split()

n = int(n_m[0])
m = int(n_m[1])

input_count = n

content_view = []
while input_count:
    views = []
    for view in input():
        views.append(view)
    content_view.append(views)
    input_count -= 1

input_count = n

content_type = []
while input_count:
    types = []
    for type in input():
        types.append(type)
    content_type.append(types)
    input_count -= 1

y_list = []
o_list = []

for i in range(n):
    for j in range(m):
        view = content_view[i][j]
        type = content_type[i][j]
        priority = type_priority_map[type]

        content = Content(view, type, priority, i, j)
        if view == 'Y':
            y_list.append(content)
        elif view == 'O':
            o_list.append(content)

y_list.sort()
o_list.sort()

for y in y_list:
    print(y.type, y.priority, y.row, y.col)
for o in o_list:
    print(o.type, o.priority, o.row, o.col)
