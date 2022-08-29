def reverse(llist):
    # Write your code here
    cur = llist
    next_cur = cur.next
    if next_cur == None:
        return cur
    cur.next = None
    cur.prev = next_cur
    cur = next_cur
    next_cur = cur.next
    if next_cur == None:
        cur.next = cur.prev
        cur.prev = None
        return cur
    while next_cur.next:
        cur.next = cur.prev
        cur.prev = next_cur
        cur = next_cur
        next_cur = cur.next
    
    cur.next = cur.prev
    cur.prev = next_cur
    next_cur.next = cur
    return next_cur