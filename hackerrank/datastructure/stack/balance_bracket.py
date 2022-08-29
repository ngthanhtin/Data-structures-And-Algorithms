ef isBalanced(s):
    # Write your code here
    stack_ = []
    if s[0] == [')', ']', '}']:
        return 'NO'
    stack_.insert(0, s[0])
    
    index = 1
    while index < len(s):
        if len(stack_) == 0:
            if s[index] == [')', ']', '}']:
                return 'NO'
            stack_.insert(0, s[index])
            index += 1
            continue
        if s[index] in [')', ']', '}']:
            bracket1 = stack_.pop(0)
            if (bracket1 == '(' and s[index] == ')') or \
                (bracket1 == '[' and s[index] == ']') or \
                (bracket1 == '{' and s[index] == '}'):
                index += 1
            else:
                return 'NO'
        else:
            stack_.insert(0, s[index])
            index += 1
    if len(stack_) > 0:
        return 'NO'
    return 'YES'