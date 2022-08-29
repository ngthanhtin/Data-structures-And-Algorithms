def getMax(operations):
    # Write your code here
    max_num = 0
    max_arr = [0]
    s = []
    answers = []
    for q in operations:
        if len(q) > 1: # 1
            strings = q.split(' ')
            x = int(strings[1])
            s.insert(0, x)
            if x >= max_num:
                max_num = x
                max_arr.insert(0, max_num)
        if q == '2':
            if len(s) != 0:
                val = s.pop(0)
                if val == max_num:
                    max_arr.remove(max_num)
                    max_num = max_arr[0]
        if q == '3':
            answers.append(max_arr[0])
    return answers