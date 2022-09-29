//利用字符串反序列化二叉树
//还是和层序遍历一样，利用队列


#include "include.h"

using namespace std;


 struct TreeNode {
     int val;
    TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
    
//空null用'/0'表示

//此代码有bug，即只能表示-128~127,所以最好用字符串相加,并用[],等形式存入数字
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;

        TreeNode* root = new TreeNode(data[0]);
        queue<TreeNode*> m_que;
        int i = 1;
        m_que.push(root);

        while(!m_que.empty()){

            TreeNode* node = m_que.front();
            m_que.pop();

            if(data[i] != '\0'){
                node->left = new TreeNode(data[i]);
                m_que.push(node->left);
            }
            i++;

            if(data[i] != '\0'){
                node->right = new TreeNode(data[i]);
                m_que.push(node->right);
            }
            i++;
            
        }
        return root;
    }