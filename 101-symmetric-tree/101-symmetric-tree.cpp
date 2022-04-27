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
   /* bool checkSymRecur(TreeNode *leftSide, TreeNode *rightSide)
    {
        if(!leftSide && !rightSide)
            return true;
        
        if((!leftSide && rightSide) || (leftSide && !rightSide))
            return false;
        
        if(leftSide->val!=rightSide->val)
            return false;
        
        if(!checkSym(leftSide->left, rightSide->right))
            return false;
        
        if(!checkSym(leftSide->right, rightSide->left))
            return false;
        
        return true;
    } */
    
    bool checkSymIter(TreeNode *leftSide, TreeNode *rightSide)
    {
        if(!leftSide && !rightSide)
            return true;
        
        if((!leftSide && rightSide) || (leftSide && !rightSide))
            return false;
        
        if(leftSide->val!=rightSide->val)
            return false;
        
        queue<TreeNode*> leftree;
        queue<TreeNode*> rightree;
        
        leftree.push(leftSide);
        rightree.push(rightSide);
        
        while(!leftree.empty() && !rightree.empty())
        {
            
            for(int i=0; i<leftree.size(); i++)
            {
                TreeNode *temp1=leftree.front();
                TreeNode *temp2=rightree.front();
                
                if(temp1->val!=temp2->val)
                    return false;
                
                leftree.pop(), rightree.pop();
                
                if((temp1->left && !temp2->right) || (!temp1->left && temp2->right))
                    return false;
                
                if((temp1->right && !temp2->left) || (!temp1->right && temp2->left))
                    return false;
                
                if(temp1->left)
                {
                    leftree.push(temp1->left);
                    rightree.push(temp2->right);
                }
                
                if(temp1->right)
                {
                    leftree.push(temp1->right);
                    rightree.push(temp2->left);
                }
            }
        }
        
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
       // return checkSymRecur(root->left, root->right);
        return checkSymIter(root->left, root->right);
    }
};