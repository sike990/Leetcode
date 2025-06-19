/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root , TreeNode* p , vector<TreeNode*> &path1 , vector<TreeNode*> &temp){

        if(root == nullptr)return;

        if(root == p){
            temp.push_back(p);
            path1 = temp;
            return;
        }
        temp.push_back(root);
        solve(root -> left , p , path1 , temp);
        solve(root -> right , p , path1 , temp);
        temp.pop_back();

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        vector<TreeNode*> temp;
        solve(root , p , path1 , temp);
        temp.clear();
        solve(root , q , path2 , temp);

        unordered_map<int,int> mp;
        for(int i = 0 ; i < path1.size() ; i++){
            TreeNode* node = path1[i];
            int value = node -> val;
            mp[value] = 1;
        }
        for(int i = path2.size()-1 ; i >= 0; i--){
            TreeNode* node = path2[i];
            int value = node -> val;
            if(mp.find(value) != mp.end())return path2[i];
        }

        return nullptr;
    }
};