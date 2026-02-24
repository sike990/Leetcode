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
int ans;
class Solution {
public:
    void sum(TreeNode* root, string &take){
        if(root == nullptr)return;
        if(root->left == nullptr && root->right == nullptr){
             if(root->val){
            take = take + "1";
        }
        else{
            take = take + "0";
        }
            int pwr = 0;
            for(int i = take.length()-1; i >= 0 ; i--){
                if(take[i] == '1')
                ans += pow(2,pwr);
                pwr++;
            }
            take.pop_back();
            return;
        }
        if(root->val){
            take = take + "1";
        }
        else{
            take = take + "0";
        }
        sum(root->left,take);
        //take.pop_back();

        sum(root->right,take);
        take.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        string take = "";
        sum(root,take);
        return ans;
    }
};