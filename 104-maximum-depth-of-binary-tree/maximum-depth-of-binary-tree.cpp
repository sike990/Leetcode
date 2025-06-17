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
    int maxDepth(TreeNode* root) {
        if(root == nullptr)return 0;
        stack<pair<TreeNode* , int >> st;
        st.push({root , 1});
        int ans = 0;
        while(!st.empty()){

            pair<TreeNode* , int> myp = st.top();
            st.pop();
            int lvl = myp.second;
            ans = max(ans , lvl);
            TreeNode* node = myp.first;
            if(node -> left != nullptr)st.push({node -> left , lvl + 1});
            if(node -> right != nullptr)st.push({node -> right , lvl + 1});
            
        }

        return ans;
    }
};