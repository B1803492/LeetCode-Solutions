class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        bool flag = true;
        int index1 = -1;
        int index2 = -1;
        vector<int> result;
        while (flag) {
            for (int i = 0; i < nums.size()-1; i++) {
                for (int j = i+1; j < nums.size(); j++) {
                    if(nums[i]+nums[j]==target) {
                        index1 = i;
                        index2 = j;
                        result.push_back(index1);
                        result.push_back(index2);
                        flag = false;
                    }
                }
            }
        }
        return result;
    }
};
