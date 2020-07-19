// Given a non-empty array of integers, return the k most frequent elements.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> my;
        for(int i=0;i<nums.size();i++){
            my[nums[i]]++;
        }
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for(auto it : my){
            pq.push(make_pair(it.second,it.first));
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};