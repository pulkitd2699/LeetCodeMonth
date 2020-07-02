// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

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
    int height(TreeNode *node);
    void givenLevelNodes(TreeNode *node, int level, vector<int> *temp);
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        int h = height(root);    
        for(int i=h;i>=1;i--){
            vector<int> temp;
            givenLevelNodes(root, i, &temp);
            ans.push_back(temp);
        }
        return ans;
    }
};

int Solution :: height(TreeNode *node){
    if(node == NULL) return 0;
    else{
        int lheight = height(node->left);
        int rheight = height(node->right);
        if(lheight > rheight) return lheight+1;
        else return rheight+1;
    }
}

void Solution :: givenLevelNodes(TreeNode *node, int level, vector<int> *temp){
    if(node == NULL) return;
    if(level == 1) temp->push_back(node->val);
    else if(level > 1){
        givenLevelNodes(node->left, level-1, temp);
        givenLevelNodes(node->right, level-1, temp);
    }
}