// Given a set of distinct integers, nums, return all possible subsets (the power set).

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int power_n = pow(2,n);
        for(int i=0;i<power_n;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                if(i&(1<<j)) temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};