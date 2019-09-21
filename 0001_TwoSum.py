# 用hash map然后颠倒key与value位置的想法出乎意料！
class Solution:  # Apporach 3
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        Hashmap = {}
        for i in range(len(nums)):
            comp = target - nums[i]
            if comp in Hashmap:
                return Hashmap[comp], i
            Hashmap[nums[i]] = i
