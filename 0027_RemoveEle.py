"""python:
直接删除了列表元素
c++:
使用了approach 2的方法"""


class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = 0
        while (i < len(nums)):
            if nums[i] == val:
                nums.pop(i)
            else:
                i = i + 1
        return len(nums)