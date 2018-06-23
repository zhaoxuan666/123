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
              if(pRoot==NULL)//判断是否为空
                return m;
            q.push(pRoot);//首先要插入头节点
            while(!q.empty())
            {
                vector<int>tmp;//创建每行添加的容器
                int i=0;int s=q.size();//计算每行的大小，输出这行填入下行
                while( i++ < s )
                {
                    TreeNode*kk=q.front();
                   tmp.push_back(kk->val);
                    q.pop();
                    if(kk->left)//判断是否为空
			q.push(kk->left);
                    if(kk->right)q.push(kk->right);
                }
                m.push_back(tmp);//插入
            }
            return m;
        }
    
};