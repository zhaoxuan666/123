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
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> S;
        vector<int> V;
        TreeNode *tmp=NULL;
        TreeNode *cur=root;
        TreeNode *prev=NULL;

        while(!S.empty()||cur!=NULL){
            while(cur!=NULL)
            {
                S.push(root);
                root=root->left;
            }
            tmp=S.top();
            if(tmp->right==NULL||tmp->right==prev)
        	{
        		V.push_back(tmp.top());
			prev=cur;
			S.pop();
        	}
		else
			cur=tmp->right;
        }
        return V;
    }
};
