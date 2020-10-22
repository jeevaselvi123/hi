class TreeNode:
    def __init__(self,value):
        self.left=None 
        self.right=None
        self.data=value
def inorder(tree):
    temp=tree
    stack=[]