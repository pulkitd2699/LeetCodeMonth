// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return ans;
        stack<struct TreeNode *> cL;
        stack<struct TreeNode *> nL;
        cL.push(root);
        bool LtoR = true;
        vector<int> v;
        while(!cL.empty()){
            struct TreeNode *temp = cL.top();
            cL.pop();
            if(temp){
                v.push_back(temp->val);
                if(LtoR){
                    if(temp->left) nL.push(temp->left);
                    if(temp->right) nL.push(temp->right);
                }
                else{
                    if(temp->right) nL.push(temp->right);
                    if(temp->left) nL.push(temp->left);
                }
            }
            if(cL.empty()){
                ans.push_back(v);
                LtoR = !LtoR;
                v.clear();
                swap(cL,nL);
            }
        }
        return ans;
    }
};