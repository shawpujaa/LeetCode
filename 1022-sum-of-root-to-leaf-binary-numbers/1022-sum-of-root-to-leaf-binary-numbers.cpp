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
    int num=0;
    vector<int> bin;
    
    bool isLeaf(TreeNode *temp)
    {
        if(temp->left==0 && temp->right==0)
            return true;
        
        return false;
    }
    
    void getNum(vector<int> biNum)
    {
        int x=1;
        for(int i=biNum.size()-1;i>=0;i--)
        {
            if(biNum[i])
            num+=x;
            x=x<<1;
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        
        bin.push_back(root->val);
        
        if(isLeaf(root))
            getNum(bin);
        else
        {
            if(root->left)
            {
                sumRootToLeaf(root->left);
                bin.pop_back();
            }
            if(root->right)
            {
                sumRootToLeaf(root->right);
                bin.pop_back();
            }
        }
        
        return num;
    }
};