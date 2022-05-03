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
class FindElements {
public:
    TreeNode *Troot=0;
    FindElements(TreeNode* root, int x=0) {
        if(!root)
            return;
        
        if(Troot==0)
            Troot=root;
        
        root->val=x;
        FindElements(root->left, 2*x+1);
        FindElements(root->right, 2*x+2);
        
    }
    
    bool get(int x, TreeNode *temp)
    {
        if(!temp || x<temp->val)
            return false;
        if(x==temp->val)
            return true;
        
        if(get(x, temp->left))
            return true;
        if(get(x, temp->right))
            return true;
        
        return false;
    }
    
    bool find(int target) {
       return get(target, Troot);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */