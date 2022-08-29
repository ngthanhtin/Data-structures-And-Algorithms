def equalStacks(h1, h2, h3):
    # Write your code here
    sum1 = sum(h1)
    sum2 = sum(h2)
    sum3 = sum(h3)
    v1,v2,v3 = 0,0,0
    if sum1 == sum2 and sum2 == sum3:
        return sum1
    while sum1 != sum2 or sum2 != sum3 or sum1 != sum3:
        if sum1 > sum2 and sum1 > sum3:
            v1 = h1.pop(0)
        if sum2 > sum1 and sum2 > sum3:
            v2 = h2.pop(0)
        if sum3 > sum1 and sum3 > sum2:
            v3 = h3.pop(0)
        if sum1 == sum2 and sum1 > sum3:
            if h1[0] <= h2[0]:
                v1 = h1.pop(0)
            else:
                v2 = h2.pop(0)
        if sum2 == sum3 and sum2 > sum1:
            if h2[0] <= h3[0]:
                v2 = h2.pop(0)
            else:
                v3 = h3.pop(0)
        if sum1 == sum3 and sum1 > sum2:
            if h1[0] < h3[0]:
                v1 = h1.pop(0)
            else:
                v3 = h3.pop(0)
        sum1 = sum1 - v1
        sum2 = sum2 - v2
        sum3 = sum3 - v3
        v1, v2, v3 = 0, 0, 0
    return sum1