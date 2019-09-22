class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        '''Time Limit'''
        # if not nums:
        #     return 0
        # ele=nums[0]
        # inx=[0,]
        # for i in range(1,len(nums)):
        #     if nums[i]!=ele:
        #         inx.append(i)
        #         ele=nums[i]
        # for i in range(len(nums)-1,-1,-1):
        #     if i not in inx:
        #         nums.pop(i)
        # return len(nums)

        '''standard solution'''
        if not nums:
            return 0
        i = 0
        for j in range(1, len(nums)):
            if nums[i] != nums[j]:
                i += 1
                nums[i] = nums[j]
        return i + 1
