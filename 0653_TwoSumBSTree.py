"""
值得注意的是特性：
二叉查找树（英语：Binary Search Tree），也称为二叉搜索树、***有序***二叉树（ordered binary tree）或排序二叉树（sorted binary tree），是指一棵空树或者具有下列性质的二叉树：

若任意节点的左子树不空，则左子树上所有节点的值均小于它的根节点的值；
若任意节点的右子树不空，则右子树上所有节点的值均大于它的根节点的值；
任意节点的左、右子树也分别为二叉查找树；
没有键值相等的节点。

本题首先遍历所有值，放入一个无序集合set，然后进行搜索。"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        btree = set([])
        self.walkthrough(root, btree)
        for ele in btree:
            comp = k - ele
            if comp in btree - set([ele]):
                return True
        return False

    def walkthrough(self, root: TreeNode, btree: set):
        if root is not None:
            btree.add(root.val)
            self.walkthrough(root.left, btree)
            self.walkthrough(root.right, btree)
