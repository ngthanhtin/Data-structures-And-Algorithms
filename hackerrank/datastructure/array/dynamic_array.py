def dynamicArray(n, queries):
    # Write your code here
    lastAnswer = 0
    arr = []
    answer_arr = []
    num_queries = len(queries)
    arr = [[] for i in range(n)]
    for i in queries:
        q,x,y = i[0], i[1], i[2]
        if q == 1:
            idx = (x^lastAnswer)%n
            arr[idx].append(y)
        elif q == 2:
            idx = (x^lastAnswer)%n
            lastAnswer = arr[idx][y%len(arr[idx])]
            answer_arr.append(lastAnswer)
    return answer_arr