def twoSum(self, nums: List[int], target: int) -> List[int]:
	Hashmap={}
	for i in range(len(nums)):
		comp=target-nums[i] 
		if comp in Hashmap:
			return Hashmap[comp],i
		Hashmap[nums[i]]=i
