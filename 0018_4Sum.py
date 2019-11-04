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
要点就是减小循环次数，通过数学手段先判定不需要的循环及时中止
'''


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        if nums == []:
            return []
        res = list()
        for i in range(len(nums) - 3):
            # 以下if 语句多半是从数学角度考虑，减少循环次数！
            if nums[i] > target >= 0:  # 每组的首个数字如果大于target，那么本组不可能，之后也不可能，如果是target负数，就不一样了
                break
            if nums[i] * 4 > target:    # 最小值的4倍大于target，自然加上后面3个值必定大于target
                break
            if nums[i] + 3 * nums[i + 1] > target:
                break
            if nums[i] + nums[i + 1] + 2 * nums[i + 2] > target:
                break
            if nums[i] + nums[len(nums) - 1] * \
                    3 < target:    # 初值加上三倍的最大值依旧小于target，那么初值必须上升
                continue
            if i > 0 and nums[i] == nums[i - 1]:  # 去重, i>0 保证nums[i]至少已经被使用了一次
                continue
            for j in range(i + 1, len(nums) - 2):
                k = j + 1
                l = len(nums) - 1
                if nums[i] + nums[j] + 2 * nums[l] < target:
                    continue
                if j > i + 1 and nums[j] == nums[j -
                                                 1]:  # 去重，j >i+1 也是确保这个数字使用了一次
                    continue
                while k < l:
                    s = nums[i] + nums[j] + nums[k] + nums[l]
                    if s == target:
                        res.append([nums[i], nums[j], nums[k], nums[l]])
                        while k < l and nums[k] == nums[k + 1]:
                            k += 1
                        while k < l and nums[l] == nums[l - 1]:
                            l -= 1
                        k += 1
                        l -= 1
                    elif s < target:
                        k += 1
                    else:
                        l -= 1
        return res
