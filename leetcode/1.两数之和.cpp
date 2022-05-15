/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.find(target - nums[i]) != indices.end()) {
                return {indices[target - nums[i]], i};
            }
            indices[nums[i]] = i;//大量空间
        }
        return {};
        /* vector<int> sum;
        auto beg = nums.begin();
        auto edn = nums.end();
        int i;
        for (auto it = beg; it != edn; it++){
            i = target - *it;
            for (auto jt = it+1; jt != edn; jt++){
                if (*jt == i){
                    sum.push_back(it-beg);
                    sum.push_back(jt-beg);
                    return sum;
                }
            }        
        }
        return {0};*/
        /*
        vector<int> sum;
        vector<int> nums2;
        vector<int>::iterator it = nums.begin();
        for (; it != nums.end(); it++)
        {
            nums2.push_back(target - *it);
        }
        for (it = nums.begin(); it != nums.end(); it++){
            for (auto jt = nums2.begin() + 1 + (it - nums.begin()); jt != nums2.end(); jt++){
                if (*it == *jt ){
                    sum.push_back(it-nums.begin());
                    sum.push_back(jt-nums2.begin());
                    return sum;
                }
            }        
        }
        return {0};*/
    }
};
// @lc code=end

