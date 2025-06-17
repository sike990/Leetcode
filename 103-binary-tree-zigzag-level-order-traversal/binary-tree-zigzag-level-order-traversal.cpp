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
        void solve(TreeNode * root , vector<vector<int>> &ans , int lvl){

        if(root == nullptr)return;
        if(ans.size() <= lvl)ans.resize(lvl+1);
        ans[lvl].push_back(root -> val);

        solve(root -> left , ans , lvl + 1);
        solve(root -> right , ans , lvl + 1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root , ans , 0);
        int lvl = 1;
        for(vector<int> &v : ans){
            if(!(lvl&1))reverse(v.begin() , v.end());
            lvl++;
        }
        return ans;
    }
};