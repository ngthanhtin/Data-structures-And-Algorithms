def removeDuplicates(llist):
    # Write your code here
    cur = llist
    before_cur = cur
    
    while cur:
        if cur.next and cur.next.data == cur.data:
            cur = cur.next
        else:
            before_cur.next = cur.next
            cur = cur.next
            before_cur = cur
            
    return llist