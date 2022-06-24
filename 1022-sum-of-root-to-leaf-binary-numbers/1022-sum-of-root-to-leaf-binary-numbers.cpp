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
    int sum=0;
    int getNum(vector<int> num)
    {
        int x=1, number=0;
        
        for(int i=num.size()-1;i>=0;i--)
        {
            if(num[i]==1)
                number+=x;
            
            x=x*2;
        }
        
        return number;
    }
    
    void getSum(TreeNode *temp, vector<int> num)
    {
        if(!temp)
            return;
        
        num.push_back(temp->val);
        if(!temp->left && !temp->right)
        {
            sum+=getNum(num);
            return;
        }
        
        getSum(temp->left, num);
        getSum(temp->right, num);
        
    }
    
    int sumRootToLeaf(TreeNode* root) {
        vector<int> num;
        getSum(root, num);
        
        return sum;
    }
};