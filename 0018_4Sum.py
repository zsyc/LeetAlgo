''' Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
'''
def fourSum(nums,target):
    nums.sort()
    if nums==[]:
        return []
    res=list()
    for i in range(len(nums)-3):
        if nums[i]>target:  # 每组的首个数字如果大于target，那么本组不可能
            break
        if i>0 and nums[i]==nums[i-1]:  #去重
            continue
        

