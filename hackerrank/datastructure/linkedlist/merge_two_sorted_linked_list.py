def mergeLists(head1, head2):
    cur1 = head1
    cur2 = head2
    is_1_first = 0
    if head1.data <= head2.data:
        is_1_first = 1    
        
    before_cur1 = cur1
    before_cur2 = cur2
    while cur1 and cur2:
        while cur1 and cur2 and cur1.data <= cur2.data:
            before_cur1 = cur1
            cur1 = cur1.next
            if cur1 and cur1.data > cur2.data:
                before_cur1.next = cur2
                before_cur2 = before_cur1
                before_cur1 = cur1
        while cur1 and cur2 and cur2.data <= cur1.data: 
            before_cur2 = cur2
            cur2 = cur2.next
            if cur2 and cur2.data > cur1.data:
                before_cur2.next = cur1
                before_cur1 = before_cur2
                before_cur2 = cur2
    if cur1 == None:
        before_cur1.next = cur2
    if cur2 == None:
        before_cur2.next = cur1
    if is_1_first:
        return head1
    return head2