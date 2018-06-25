/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> S;
        vector<int> V;
        TreeNode *tmp;
        while(!S.empty()||root!=NULL){
            while(root!=NULL)
            {
                S.push(root);
                root=root->left;
                V.push_back(S.top()->val);
            }
            tmp=S.top();
            S.pop();
            root=tmp->right;
        }
        return V;
    }
};