def findMergeNode(h1, h2):
    t1 , t2 = h1 , h2
    while t1 or t2:
        if t1 == t2:
            return t1.data
        t1 = t1.next if t1 else h2
        t2 = t2.next if t2 else h1