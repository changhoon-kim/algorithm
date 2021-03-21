#12:00 ~ 23:59
#11:00 ~ 18:00

def is_duplicate(start_hour, start_min, end_hour, end_min, posible_start_hour, posible_start_min, posible_end_hour, posible_end_min):
    if end_hour < posible_start_hour:
        return False
    elif end_hour == posible_start_hour:
        if end_min <= posible_start_min:
            return False

    if start_hour > posible_end_hour:
        return False
    elif start_hour == posible_end_hour:
        if start_min >= posible_end_min:
            return False

    return True

def get_print_time(data):
    if data < 10:
        return '0%d' %(data)

    return str(data)

member_count = int(input())

posible_start_hour = None
posible_start_min = None
posible_end_hour = None
posible_end_min = None
result = None

while member_count:
    time = input()

    if result == -1:
        member_count -= 1
        continue

    sp = time.split('~')
    start = sp[0].strip()
    start_hour = int(start[0:2])
    start_min = int(start[3:])

    end = sp[1].strip()
    end_hour = int(end[0:2])
    end_min = int(end[3:])

    if posible_start_hour is None:
        posible_start_hour = start_hour
        posible_start_min = start_min
        posible_end_hour = end_hour
        posible_end_min = end_min
        member_count -= 1
        continue

    if not is_duplicate(start_hour, start_min, end_hour, end_min, posible_start_hour, posible_start_min, posible_end_hour, posible_end_min):
        result = -1
        member_count -= 1
        continue

    posible_start_hour = max(posible_start_hour, start_hour)
    posible_start_min = max(posible_start_min, start_min)
    posible_end_hour = min(posible_end_hour, end_hour)
    posible_end_min = min(posible_end_min, end_min)

    member_count -= 1

if result == -1:
    print(-1)
else:
    print('%s:%s ~ %s:%s'%(get_print_time(posible_start_hour),
                           get_print_time(posible_start_min),
                           get_print_time(posible_end_hour),
                           get_print_time(posible_end_min)))
