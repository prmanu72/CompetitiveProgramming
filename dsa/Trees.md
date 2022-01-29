1. [LCA](#LCA)
2. [Inorder-traversal](#Inorder-traversal)
3. [Inorder Traversal of Cartesian Tree](#Inorder-Traversal-of-Cartesian-Tree)
4. [Morris-traversal](#Morris-traversal)
5. [Recover BST](#Recover-BST)
6. [Flatten Binary Tree to Linked List](#Flatten-Binary-Tree-to-Linked-List)
7. [Valid BST from Preorder](#Valid-BST-from-Preorder)

#### LCA
```
bool is1=false, is2=false;

void check(node* root, int n1, int n2)
{
    if(root == NULL) return;
    if(is1 && is2) return;
    
    if(root->val == n1) is1 = true;
    if(root->val == n2) is2 = true;
    
    check(root->left, n1, n2);
    check(root->right, n1, n2);
}
node* lcaUtil(node* root, int n1, int n2)
{
    if(!root) return NULL;
    
    if(root->val == n1 || root->val == n2)
    return root;
    
    node *left = lcaUtil(root->left, n1, n2);
    node *right = lcaUtil(root->right, n1, n2);
    
    if(left && right)
    return root;
    return (left==NULL? right: left);
}
node* findLCA(node* root, int n1, int n2)
{
    is1=false;
    is2=false;
    check(root,n1,n2);
    if(!is1 || !is2) return NULL;
    return lcaUtil(root, n1, n2);
}
```

#### Inorder-traversal
```
void inorder(node* root)
{
    if(root==NULL) return;
    
    inorder(root->left);
    cout<<root->val;
    inorder(root->right);
}
---------------------------------------------------------------------------------------------------
#define node TreeNode
vector<int> Solution::inorderTraversal(TreeNode* A) 
{
    stack<node*> sk;
    vector<int> res;
    
    node *curr=A;
    while(curr)
    {
        sk.push(curr);
        curr=curr->left;
    }
    while(sk.size())
    {
        curr=sk.top()->right;
        res.push_back(sk.top()->val);
        sk.pop();
        while(curr)
        {
            sk.push(curr);
            curr=curr->left;
        }
    }
    return res;
}
```

#### Inorder-Traversal-of-Cartesian-Tree
* Cartesian tree :  is a heap ordered binary tree, where the root is greater than all the elements in the subtree.
* For inorder traversal, left subtree values are present in left of root value and right sub tree  values on right
```
 #define node TreeNode
 node* fun(vector<int> &v,vector<int>::iterator i, vector<int>::iterator j)
 {
    if(j-i<=0) return NULL;
    
    auto it=max_element(i,j);
    node* root=new node(*it);
    root->left=fun(v,i,it);
    root->right=fun(v,it+1,j);
    return root;
 }
TreeNode* Solution::buildTree(vector<int> &A) 
{
    if(A.size()==0) return NULL;
    return fun(A,A.begin(),A.end());
}
```
#### Morris-traversal
[Inorder & postorder](https://github.com/mission-peace/interview/blob/master/src/com/interview/tree/MorrisTraversal.java)
```
void MorrisTraversal(struct tNode* root)
{
    struct tNode *current, *pre;
 
    if (root == NULL)
        return;
 
    current = root;
    while (current != NULL) {
 
        if (current->left == NULL) {
            printf("%d ", current->data);
            current = current->right;
        }
        else {
 
            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL
                   && pre->right != current)
                pre = pre->right;
 
            /* Make current as the right child of its
               inorder predecessor */
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
 
            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else {
                pre->right = NULL;
                printf("%d ", current->data);
                current = current->right;
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
}
```
#### Recover-BST
```
// O(N) time, O(N) space
    node *first=NULL, *second=NULL;
    node *prev = new node(INT_MIN);
    
    void inorder(node* root){
        if(!root) return;
        
        inorder(root->left);
        if(!first && prev->val > root->val)
        first=prev;
        
        if(first && prev->val > root->val)
        second = root;
        
        prev = root;
        inorder(root->right);
    }
    void recoverBST(node* root){
        inorder(root);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
 ----------------------------------------------------------------------------------
 //Morris traversal : O(N) time, O(1) space
node *first=NULL, *second=NULL;
node* prev = new node(INT_MIN);
recoverBST(node* root){
    if(root=NULL) return;
    
    node* cur=root;
    while(cur){
        if(!cur->left){
        
            if(prev && prev-> val > cur->val){
                if(!first) {
                    first = prev;
                }
                second  = root;
            }
            prev = root;
            cur=cur->right;
        }
        else{
            node* pred = cur->left;
            
            while(pred->right!=NULL && pred->right!=cur)
                pred=pred->right;
            
            if(pred->right == NULL){
                pred->right = cur;
                cur=cur->left;
            }
            else{
                pred->right=NULL;
               
                if(prev && prev-> val > cur->val){
                if(!first) {
                    first = prev;
                }
                second  = root;
                }
                prev = root;
                
                cur=cur->right;
            }
        }
    }
    
    int tmp = first->val;
    first->val = second->val;
    second->val = tmp;
}
```

#### Flatten-Binary-Tree-to-Linked-List
```
#define node TreeNode
TreeNode* Solution::flatten(TreeNode* A) {
    node* root=A;
    if(!A) return A;
    
    while(A)
    {
        if(A->left)
        {
            node* t=A->left;
            while(t->right)
            t=t->right;
            
            t->right=A->right;
            A->right=A->left;
            A->left=NULL;
        }
        A=A->right;
    }
    return root;
}
```

#### Valid-BST-from-Preorder
```
int Solution::solve(vector<int> &A) {
    int n=A.size();
    if(n<=1) return 1;
    
    stack<int> s;
    int root=INT_MIN;
    
    for(int i=0;i<n;i++)
    {
        if(A[i]<root) return 0;
        while(s.size() && s.top()<A[i])
        {
            root=s.top();
            s.pop();
        }
        s.push(A[i]);
    }
    return 1;
}
```
#### Kth Smallest Element In Tree
```
 vector<int> v;
 void order(TreeNode* root)
 {
     if(root)
     {
        order(root->left);
        v.push_back(root->val);
        order(root->right);
     }
 }
int Solution::kthsmallest(TreeNode* A, int B) {
    v.clear();
    if(A==NULL) return 0;
    
    order(A);
    if(v.size()<B)
        return -1;
    
    return v[B-1];    
}
```

#### 2-Sum Binary Tree
```
set<int> s;
#define node TreeNode
bool solve(node *root,int k)
{
    if(root)
    {
        if(s.find(k-root->val)!=s.end())
        return 1;
        s.insert(root->val);
        return solve(root->left,k) || solve(root->right,k);
    }
    return false;
}

int Solution::t2Sum(TreeNode* A, int B) {
    s.clear();
    return solve(A,B);
}
```
#### Height-of-tree
```
int height(struct node* node)
{
	// base case tree is empty
	if (node == NULL)
		return 0;

	// If tree is not empty then height = 1 + max of left
	// height and right heights
	return 1 + max(height(node->left), height(node->right));
}
```

#### Diameter-of-tree
```
int diameter(struct node* tree, int &res)
{
	if (tree == NULL)
		return 0;
		
	int l = diameter(tree->left,res);
	int r = diameter(tree->right,res);
	res=max(res,l+r+1);
	return max(l,r)+1;
}
int main()
{
...........
int res=INT_MIN;
diameter(root,res);
}
```
#### Maximum-path-sum(node-to-node)
```
int solve(Node *root, int &res)
{
	if(root==NULL)
		return 0;

	int l=solve(root->left,res);
	int r=solve(root->right,res);

	int temp=max(max(l,r)+root->value,root->value);
	int ans=max(temp,l+r+root->value);
	res=max(res,ans);

	return res;
}
//res holds ans

{
	int res=INT_MIN;
	int k=solve(root,res);
	return res;
}
```

#### Max-path-sum(leaf-to-leaf)
```
int maxPathSum(struct Node *root, int& res)
{
    if(root==NULL) return 0;
    if(!root->left && !root->right) return root->data;
    
    int l = maxPathSum(root->left, res);
    int r = maxPathSum(root->right, res);
    
    int tmp = max(l,r)+root->data;
    res = max(res, l+r+root->data);
    
    return tmp;
}
```

#### Trie
```
#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

#define node struct TrieNode

struct TrieNode
{
	vector<node*> children;
	bool isEndOfWord;
	TrieNode()
	{
	    isEndOfWord=false;
	    children=vector<node*>(26,NULL);
	}
};

void insert(struct TrieNode *root, string key)
{
	node *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			{
			    
			    pCrawl->children[index] =new node();
			}

		pCrawl = pCrawl->children[index];
	}
	pCrawl->isEndOfWord = true;
}


bool search(struct TrieNode *root, string key)
{
	node *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl->isEndOfWord);
}

int main()
{
	
	string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their" };
	int n = sizeof(keys)/sizeof(keys[0]);

	node* root=new node();

	for (int i = 0; i < n; i++)
		insert(root, keys[i]);

	search(root, "the")? cout << "Yes\n" :	cout << "No\n";
	search(root, "these")? cout << "Yes\n" :	cout << "No\n";
	return 0;
}
```
