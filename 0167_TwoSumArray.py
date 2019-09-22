class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        Hashmap = {}
        for i in range(len(numbers)):
            comp = target - numbers[i]
            if comp in Hashmap:
                return Hashmap[comp] + 1, i + 1
            Hashmap[numbers[i]] = i
