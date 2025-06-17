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
    // void solve(TreeNode * root , vector<vector<int>> &ans , int lvl){

    //     if(root == nullptr)return;
    //     if(ans.size() <= lvl)ans.resize(lvl+1);
    //     ans[lvl].push_back(root -> val);

    //     solve(root -> left , ans , lvl + 1);
    //     solve(root -> right , ans , lvl + 1);
    // }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)return {};
        //solve(root , ans , 0);
        stack<pair<TreeNode* , int>> st;
        st.push({root , 0});
        while(!st.empty()){
             pair<TreeNode* , int> myp = st.top();
             st.pop();
             int lvl = myp.second;
             TreeNode* node = myp.first;
             if(ans.size() <= lvl)ans.resize(lvl+1);
             ans[lvl].push_back(node -> val);
             if(node -> right != nullptr)st.push({node -> right , lvl + 1});
             if(node -> left != nullptr)st.push({node -> left , lvl + 1});
             
        }
        return ans;
    }
};