/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
          
       		 queue<TreeNode*> q;
          	  vector<vector<int>> m;
              if(pRoot==NULL)//�ж��Ƿ�Ϊ��
                return m;
            q.push(pRoot);//����Ҫ����ͷ�ڵ�
            while(!q.empty())
            {
                vector<int>tmp;//����ÿ����ӵ�����
                int i=0;int s=q.size();//����ÿ�еĴ�С�����������������
                while( i++ < s )
                {
                    TreeNode*kk=q.front();
                   tmp.push_back(kk->val);
                    q.pop();
                    if(kk->left)//�ж��Ƿ�Ϊ��
			q.push(kk->left);
                    if(kk->right)q.push(kk->right);
                }
                m.push_back(tmp);//����
            }
            return m;
        }
    
};