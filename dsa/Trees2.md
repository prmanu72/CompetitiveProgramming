#### Binary tree left view
```
void leftViewUtil(struct Node *root,
                int level, int *max_level)
{
    // Base Case
    if (root == NULL) return;
 
    // If this is the first Node of its level
    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }
 
    // Recur for left subtree first,
    // then right subtree
      leftViewUtil(root->left, level + 1, max_level);
    leftViewUtil(root->right, level + 1, max_level);
     
}
 
// A wrapper over leftViewUtil()
void leftView(struct Node *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}
```

#### Binary tree right side view
```
 void sol(TreeNode* A, vector<int> &ans,int l)
 {
     if(A==NULL)
     return;
     if(ans.size()<l)
     ans.push_back(A->val);
     sol(A->right,ans,l+1);
     sol(A->left,ans,l+1);
 }
vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;
    if(A==NULL)
    return ans;
    sol(A,ans,1);
    return ans;
}
-----------------------------------------

void rightViewUtil(struct Node *root,
                   int level, int *max_level)
{
    // Base Case
    if (root == NULL) return;
 
    // If this is the last Node of its level
    if (*max_level < level)
    {
        cout << root->data << "\t";
        *max_level = level;
    }
 
    // Recur for right subtree first,
    // then left subtree
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}
 
// A wrapper over rightViewUtil()
void rightView(struct Node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}
---------------------------------------------------
vector<int> rightSideView(TreeNode* root) {
        vector<int> sol;
        if(!root)
            return sol;
        queue<node*> q;
        sol.push_back(root->val);
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0; i<n; i++)
            {
                node* tmp=q.front();
                q.pop();
                if(tmp->left)
                {
                    q.push(tmp->left);
                }
                if(tmp->right)
                {
                    q.push(tmp->right);
                }
            }
            if(!q.empty() && q.back() )
            {
                sol.push_back(q.back()->val);
            }
                
        }
        return sol;
    }
```

