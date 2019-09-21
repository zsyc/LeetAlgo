// 借鉴网友的答案，思路就是用一个新的list，每次比较一个，然后连接小的node

// 注意在c + +实现中，返回函数内部生成的指针可能因函数的销毁才失效。
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not l1:
            return l2
        if not l2:
            return l1
        head = ListNode(-100)
        temp = head
        while l1 and l2:
            if l1.val < l2.val:
                temp.next = l1
                l1 = l1.next
            else:
                temp.next = l2
                l2 = l2.next
            temp = temp.next
        if l1 is None:  # l2是有序链表，把剩下的直接链接上就可以了
            temp.next = l2
        if l2 is None:
            temp.next = l1
        head = head.next
        del temp
        return head
