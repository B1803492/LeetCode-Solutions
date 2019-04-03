/*
1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
*/

//Runtime: 28 ms, faster than 83.62% of C++ online submissions for 4Sum.
//Memory Usage: 9.2 MB, less than 100.00% of C++ online submissions for 4Sum.
//˼·������һ�����鱣�������������飬��������������Ȼ����β�������м��ƶ���������ڽ⣬���ҳ�Ŀ��ֵ��Ӧ��ԭ������±꣨��ֹ�ظ�����
//�����򷵻ؿ�vector

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) return vector<int>();
        vector<int> num,res;
        num = nums;
        sort(nums.begin(),nums.end());
        int begin = 0, end = nums.size()-1;
        while (begin < end) {
            int sum = nums[begin] + nums[end];
            if (sum < target) begin++;
            else if (sum > target)  end--;
            else {
                for (int i=0; i<num.size(); i++){
                    if (num[i] == nums[begin]) {
                        res.push_back(i);
                        break;
                    }
                }
                for (int i=0; i<num.size(); i++){
                    if (num[i] == nums[end] && i!=res[0]) {
                        res.push_back(i);
                        break;
                    }
                }
                return res;
            }
        }
        return res;
    }
};
