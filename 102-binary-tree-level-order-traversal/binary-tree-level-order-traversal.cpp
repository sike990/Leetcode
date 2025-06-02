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
    map<int , vector<int>> mp;
    void solve(TreeNode* root , int lvl){

        if(root == nullptr)return;

        mp[lvl].push_back(root->val);

        solve(root -> left , lvl + 1);
        solve(root -> right , lvl + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        mp.clear();
        vector<vector<int>> ans;
        solve(root , 0);
        for(auto i : mp)ans.push_back(i.second);
        return ans;
    }
};