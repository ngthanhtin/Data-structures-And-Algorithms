def compare_lists(llist1, llist2):
    cur1 = llist1
    cur2 = llist2
    while cur1 and cur2:
        if cur1.data != cur2.data:
            return 0
        cur1 = cur1.next
        cur2 = cur2.next
    
    if cur1 == None and cur2 == None:
        return 1
    return 0