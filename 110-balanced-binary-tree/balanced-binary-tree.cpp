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
    pair<int , bool > isbal(TreeNode* root){
        
        if(root == nullptr){
            return {0,true};
        }

        pair<int , bool > curr;

        pair<int , bool > lef = isbal(root -> left);
        pair<int , bool > rig = isbal(root -> right);
        
        curr.first = max(lef.first,rig.first) + 1;
        int diff = abs(lef.first - rig.first);
        curr.second = (diff <= 1 && lef.second && rig.second) ;
        return curr; 
    }
    bool isBalanced(TreeNode* root) {
        auto el = isbal(root);
        return el.second;
    }
};