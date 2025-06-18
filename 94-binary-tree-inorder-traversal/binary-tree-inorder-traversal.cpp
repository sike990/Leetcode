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
    // void inorder(TreeNode* root , vector<int> & ans ){

    //     if(!root)return;

    //     inorder(root -> left , ans);
    //     ans.push_back(root -> val);
    //     inorder(root -> right , ans);
    // }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        //inorder(root , ans);
        set<TreeNode*> mp;

        stack<TreeNode*> st;
        if(root != nullptr)
        st.push(root);
        while(!st.empty()){

            TreeNode* topel = st.top();
            //case to push in stack
            if(topel -> left != nullptr && mp.find(topel -> left) == mp.end()){
                st.push(topel->left);
            }
            else{
                //if left is nullptr
              //  if(topel -> left == nullptr){
                    st.pop();
                    ans.push_back(topel -> val);
                    mp.insert(topel);
                    if(topel -> right != nullptr)st.push(topel -> right);
              //  }

            }

        } 

        
        return ans;
    }
};