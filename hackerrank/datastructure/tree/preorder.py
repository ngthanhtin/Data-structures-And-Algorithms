def preOrder(root):
    #Write your code here
    if root:
        print(root.info, end= " ")
    if root.left:
        preOrder(root.left)
    if root.right:
        preOrder(root.right)