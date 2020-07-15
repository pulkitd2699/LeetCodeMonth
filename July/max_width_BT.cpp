// Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

// The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.


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
    int widthOfBinaryTree(TreeNode* root) {
        vector<unsigned> lefts;
        unsigned max_width=0;
        dfs(root, 1, 0, lefts, max_width);
        return max_width;
    }
    
private:
    void dfs(TreeNode *root, unsigned id, unsigned depth, vector<unsigned> &lefts, unsigned &max_width){
        if(!root) return;
        if(depth >= lefts.size()) lefts.push_back(id);
        max_width = max(max_width, id-lefts[depth]+1);
        dfs(root->left, 2*id, depth+1, lefts, max_width);
        dfs(root->right, 2*id+1, depth+1, lefts, max_width);
    }
};