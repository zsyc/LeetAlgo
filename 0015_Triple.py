"""
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
"""


class Solution:
    def threeSum(self, nums):
        nums.sort()     #非常重要的一步！
        if nums == []:
            return []
        res = []
        for i in range(len(nums) - 2):
            if nums[i] > 0:     # 若第一个数字为正数，因为已经排序过，所以不可能实现和为0的目标
                break                
            if i > 0 and nums[i] == nums[i - 1]:去重
                continue
            target = 0 - nums[i]
            j = i + 1
            k = len(nums) - 1           # 从后往前索引，需要好好领会内涵！
            while(j < k):
                if nums[j] + nums[k] == target:
                    res.append([nums[i], nums[j], nums[k]])
                    while(j < k and nums[j] == nums[j + 1]):    # 去重
                        j += 1
                    while(j < k and nums[k] == nums[k - 1]):
                        k -= 1
                    j += 1
                    k -= 1
                elif nums[j] + nums[k] < target:
                    j += 1
                else:
                    k -= 1
        return res

if __name__ == "__main__":
    a = Solution()
    print(a.threeSum([-1, 0, 0,0, 3, 4, -2, 2, 1, -1]))
    print(a.threeSum([0, 0,0]))
