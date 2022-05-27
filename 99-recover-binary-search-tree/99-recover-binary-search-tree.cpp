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
   /*              //TC-O(nlogn)  SC-O(n)
    int it=0;
    void getInorder(TreeNode* root, vector<int> &Inorder)
    {
        if(!root)
            return;
        
        getInorder(root->left, Inorder);
        Inorder.push_back(root->val);
        getInorder(root->right, Inorder);
        
    }
    
    void assign(TreeNode *root, vector<int> Inorder)
    {
        if(!root)
            return;
        
        assign(root->left, Inorder);
        root->val=Inorder[it];
        it++;
        assign(root->right, Inorder);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> Inorder;
        
        getInorder(root, Inorder);
        
        sort(Inorder.begin(), Inorder.end());
        
        assign(root, Inorder);
        
    }*/
    
    /*void getNodes(TreeNode *root, vector<TreeNode*> &Nodes)
    {
        if(!root)
            return;
        
        getNodes(root->left, Nodes);
        Nodes.push_back(root);
        getNodes(root->right, Nodes);
        
    }
    
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> Nodes;
        
        getNodes(root, Nodes);
        
        TreeNode *first=0, *second=0;
        //cout<<Nodes[0]->val<<Nodes[1]->val<<Nodes[2]->val;
        for(int i=1;i<Nodes.size();i++)
        {
            if(Nodes[i]<Nodes[i-1])
            {
                if(!first && !second)
                {cout<<"a";
                    first=Nodes[i-1];
                    second=Nodes[i];
                }
                else
                {
                    second=Nodes[i];
                    break;
                }cout<<"G";
            }cout<<Nodes[i-1]->val<<Nodes[i]->val;
        }
        
        swap(first->val, second->val);
        
    }*/
     bool flag=0;
     TreeNode *first=0, *second=0, *prev=0;
    
     void recover(TreeNode *root)
     {
         if(!root)
             return;
         
         recover(root->left);
         if(prev && root->val<prev->val)
         {
             if(!first)
             {
                 first=prev;
                 second=root;
             }
             else
                 second=root;
         }
         prev=root;
         recover(root->right);
     }
    
     void recoverTree(TreeNode* root) {
        
        recover(root);
         if(first && second)
         swap(first->val, second->val);
    }
};