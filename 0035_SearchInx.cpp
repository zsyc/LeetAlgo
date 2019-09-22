

class Solution {
    public:
    int searchInsert(vector < int > & nums, int target) {
        decltype(nums.size()) i = 0
        for (
            i < nums.size()
            + +i){
            if (target == nums[i]) return i
            if (target < nums[i]) return i
        }
        return i
    }
}
