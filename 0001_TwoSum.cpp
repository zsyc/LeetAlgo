//用hash map然后颠倒key与value位置的想法出乎意料！


class Solution {
    public:
    vector < int > twoSum(vector < int > & nums, int target) {
        unordered_map < int, int > hm
        int complete = 0
        for (int i=0
             i < nums.size()
             + +i){
            complete = target - nums[i]
            if (hm.find(complete) != hm.end()){
                vector < int > result = {hm[complete], i}
                return result
            }
            hm.insert(pair < int, int > (nums[i], i))
        }
    }
}
