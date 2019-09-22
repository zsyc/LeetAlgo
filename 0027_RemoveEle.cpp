/*
python:
直接删除了列表元素
c + +:
使用了approach 2的方法
*/


class Solution {
    public:
    int removeElement(vector < int > & nums, int val) {
        int i = 0, l = nums.size()
        while(i < l)
        if (nums[i] == val){
            nums[i] = nums[l - 1]
            - -l
        }
        else ++i
        return i
    }
}
