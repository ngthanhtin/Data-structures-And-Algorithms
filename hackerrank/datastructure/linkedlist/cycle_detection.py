def has_cycle(head):
    hash_node = {}
    cur = head
    while cur:
        if cur not in hash_node.keys():
            hash_node[cur] = 1
        else:
            return 1
        cur = cur.next
    return 0