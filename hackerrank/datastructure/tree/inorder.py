def inOrder(root):
    #Write your code here
    if root == None:
        return
    if root.left:
        inOrder(root.left)
    print(root.info, end=" ")
    if root.right:
        inOrder(root.right)