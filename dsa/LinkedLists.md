# LinkedLists

1. [Insertion sort](#user-content-insertionsort)
2. [Reverse LinkedList II](#user-content-reverse-linkedlist-ii)
3. [Sort binary linkedlist](#user-content-sort-binary-linkedlist)
4. [Kth node from middle](#user-content-kth-node-from-middle)
5. [Reverse alternate k-nodes](#user-content-reverse-alternate-k-nodes)
6. [Add 2 number as lists](#user-content-add-2-number-as-lists)
7. [Detect cycle and return the beginning](#user-content-detect-cycle-and-return-the-beginning)
8. [Palindrome list](#user-content-palindrome-list)
9. [Merge two sorted lists](#user-content-merge-two-sorted-lists)
10. [Remove Nth Node from List End](#user-content-remove-nth-node-from-list-end)
11. [Remove Duplicates from Sorted List](#user-content-remove-duplicates-from-sorted-list)
12. [Remove Duplicates from Sorted List II](#user-content-remove-duplicates-from-sorted-list-ii)
13. [Partition List](#user-content-partition-list)
14. [K reverse linked list](#user-content-k-reverse-linked-list)
15. [Swap List Nodes in pairs](#user-content-swap-list-nodes-in-pairs)
16. [Even Reverse](#user-content-even-reverse)
17. [Rotate List](#user-content-rotate-list)
18. [Intersection of Linked Lists](#user-content-intersection-of-linked-lists)
19. [Merge sort](#user-content-merge-sort)
20. Segregate even and odd value nodes 
	* sort like sorting binary linked list
	* make a separate dummy node for odd val nodes to append during traversal of LL.
21. [Swap kth node from start with kth node from end](#user-content-swap-kth-node-from-start-with-kth-node-from-end)
22. [Skip M delete N nodes](#user-content-skip-m-delete-n-nodes)
23. [Flattening a Linked List](#user-content-flattening-a-linked-list)
24. [Merge a linked list into another linked list at alternate positions](#user-content-merge-a-linked-list-into-another-linked-list-at-alternate-positions)
25. [Merge k sorted lists](#user-content-merge-k-sorted-lists)



 Definition for singly-linked list.
```
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 ```
 Merge function
 ```
 node* merge(node *a,node* b)
{
    if(!a) return b;
    if(!b) return a;
    
    if(a->val<b->val)
    {
        a->next=merge(a->next,b);
        return a;
    }
    else
    {
        b->next=merge(a,b->next);
        return b;
    }
}
 ```
 
 
##### Use of slow and fast pointers
```
node *s=A,*f=A;
while(f->next && f->next->next)
{
s=s->next;
f=f->next->next;
}
# s ends at (n/2 + 1)th node
-----------

while(fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
# slow ends at (n/2 )th node
```


##### Use of duplicate node
```
node *dum=(node *)malloc(sizeof(node));
node *t=dum;
```

#### Bth  node from end
Maintain h2 as Bth node from h1. When h1 comes to end, h2 will be Bth node from end 
```
    node *h1=(node *)malloc(sizeof(node));
    node *h2=(node *)malloc(sizeof(node));
    
    h1=A;h2=A;
    
    for(int i=1;i<B ;i++)
    {
        if(h1->next==NULL)
        return A->next;
        h1=h1->next;
        
    }
    while(h1->next!=NULL)
    {
        h1=h1->next;
        h2=h2->next;
    }
```

#### InsertionSort
```
 #define node ListNode
 node* sort(node *sorted, node* ins)
 {
     if(sorted==NULL || sorted->val>=ins->val)
     {
         ins->next=sorted;
         return ins;
     }
     else
     {
         node *cur=sorted;
         while(cur->next && cur->next->val<ins->val)
         {
             cur=cur->next;
         }
         ins->next=cur->next;
         cur->next=ins;
         return sorted;
     }
 }
ListNode* Solution::insertionSortList(ListNode* A) 
{
    if(!A || !A->next) return A;
    node *cur=A;
    node *sorted=NULL;
    while(cur)
    {
        node *nx=cur->next;
        sorted=sort(sorted,cur);
        cur=nx;
    }
    return sorted;
}

```
#### Reverse LinkedList II
```
#define node ListNode
 node* reverse(node *head,int k)
 {
     if(!head || !head->next) return head;
     int c=0;
     node *p=NULL,*r=NULL;
     node *q=head;
     while(q && c<k)
     {
         r=q->next;
         q->next=p;
         p=q;
         q=r;
         c++;
     }
     if(q)
     head->next=q;
    return p;
 }
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) 
{
    if(!A || !A->next) return A;
    
    node *p=A;
    int k=C-B+1;
    node *q=NULL; 
    for(int i=1;i<B;i++)
    {
        q=p;
        p=p->next;
    }
    node *tmp=reverse(p,k);
    if(q)
    q->next=tmp;
    else return tmp;
    return A;
}
```
#### Sort binary linkedlist
Input 1:
 1 -> 0 -> 0 -> 1
 Output 1:
 0 -> 0 -> 1 -> 1
 
Input 2:
 0 -> 0 -> 1 -> 1 -> 0
Output 2:
 0 -> 0 -> 0 -> 1 -> 1
```
ListNode* Solution::solve(ListNode* A) {
    if(A==NULL)return A;
    ListNode *t1 = A, *t2 = A->next;
    while(t2){
        if(t1->val==1 && t2->val==0){
            t1->val=0;
            t2->val=1;
            t1=t1->next;
            t2=t2->next;
        }else if(t1->val==1 && t2->val==1){
            t2=t2->next;
        }else{
            t1=t1->next;
            t2=t2->next;
        }
    }
    return A;
}
```
#### Kth node from middle
Input 1:

 A = 3 -> 4 -> 7 -> 5 -> 6 -> 1 6 -> 15 -> 61 -> 16
 B = 3

 Input 2:

 A = 1 -> 14 -> 6 -> 16 -> 4 -> 10
 B = 2

 Input 3:

 A = 1 -> 14 -> 6 -> 16 -> 4 -> 10
 B = 10

Output 1:

 4

 Output 2:

 14

Output 3:

 -1


```
int Solution::solve(ListNode* A, int B) {
      ListNode* p1=A;
      ListNode* p2=A;
      int midPos=0;
      while(p2 && p2->next){
            p2=p2->next->next;
            p1=p1->next;
            midPos++;
      }
      if(midPos<B)
            return -1;
      int count=midPos-B;
      ListNode* iter=A;
      for(int i=0;i<count;i++){
            iter=iter->next;
      }
      return iter->val;
}
-----------------------------------------------------------------------------
int k=0,b=-1,ans=-1,c=0;
void fun(ListNode* root)
{
    if(root)
    {
        k++;
        fun(root->next);
        c++;
        int t=k/2+1;
        if( c==(k-t+1+b))
        ans=root->val;
    }
}
int Solution::solve(ListNode* A, int B) {
    b=B;
    k=0;
    c=0;
    ans=-1;
    fun(A);
    return ans;
}

```
#### Reverse alternate k-nodes
Input 1:

 A = 3 -> 4 -> 7 -> 5 -> 6 -> 6 -> 15 -> 61 -> 16
 B = 3

 Input 2:

 A = 1 -> 4 -> 6 -> 6 -> 4 -> 10
 B = 2

Output 1:

 7 -> 4 -> 3 -> 5 -> 6 -> 6 -> 16 -> 61 -> 15

Output 2:

 4 -> 1 -> 6 -> 6 -> 10 -> 4

```
ListNode* Solution::solve(ListNode* A, int B) {
    
    ListNode *curr = A, *prev = NULL, *next = NULL;
    
    int cnt = 0;
    while(curr && cnt < B){
        
        next = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = next;
        
        cnt++;
    }
    
    if(next){
        
        A->next = next;
        cnt = 1;
        
        while(next && cnt < B){
            
            next = next->next;
            cnt++;
        }
        
        if(next->next){
            
            next->next = solve(next->next, B);
        }
    }
    
    return prev;
}

```

#### Add 2 number as lists
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)

Output: 7 -> 0 -> 8

    342 + 465 = 807

Make sure there are no trailing zeros in the output list

So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.

```
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) 
{
    if(!A) return B;
    if(!B) return A;
    int c=0;
    node *dum=(node *)malloc(sizeof(node));
    node *t=dum;
    while(A && B)
    {
        int k=A->val+B->val+c;
        node *tmp = new node(k%10);
        t->next=tmp;
        c=k/10;
        t=t->next;
        A=A->next;
        B=B->next;
    }
    while(A)
    {
        int k=A->val+c;
        node *tmp = new node(k%10);
        t->next=tmp;
        c=k/10;
        t=t->next;
        A=A->next;
    }
    while(B)
    {
        int k=B->val+c;
        node *tmp = new node(k%10);
        t->next=tmp;
        c=k/10;
        t=t->next;
        B=B->next;
    }
    if(c>0)
    {
        node *tmp = new node(k%10);
        t->next=tmp;
    }
    return dum->next;
}
```

#### Detect cycle and return the beginning
```
#define node ListNode
ListNode* Solution::detectCycle(ListNode* A) 
{
    if(!A || !A->next) return NULL;
    node *slow=A,*fast=A;
    int k=0;
    slow=slow->next;
    fast=fast->next->next;
    while(fast && fast->next)
    {
        if(slow==fast)
        {
            k=1;
            break;
        }
       slow=slow->next;
       fast=fast->next->next;
    }
    if(k)
    {
        slow=A;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
    return NULL;
}
```

#### Palindrome list
```

int ispal;
node *q;
void fun(node* root)
{
    if(root && ispal)
    {
        fun(root->next);
        if(q->val == root->val )
        q=q->next;
        else
        ispal=0;
    }
}
int Solution::lPalin(ListNode* A) {
   node *head=A;
   
    if(A==NULL || A->next==NULL) return 1;
    
    if(A->next->next==NULL)
    {
        if(A->val==A->next->val) return 1;
        else return 0;
    }

    q = A;
    ispal = 1;
    fun(A);
    return ispal;
}

-----------------------------------------------------------------------------------

node* reverse(ListNode *head)
{
    if(!head || !head->next) return head;
    node *q=head;
    node *p=NULL,*r=NULL;
    while(q)
    {
        r=q->next;
        q->next=p;
        p=q;
        q=r;
    }
    return p;
}

int Solution::lPalin(ListNode* A) {
   node *head=A;
   
    if(A==NULL || A->next==NULL) return 1;
    
    if(A->next->next==NULL)
    {
        if(A->val==A->next->val) return 1;
        else return 0;
    }
    node *fast=A;
    node *slow=A;
    
    while(fast->next && fast->next->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    node *tmp=reverse(slow->next); 
    
   // slow ends up at n/2th node
   // while(fast && fast->next)
   //{
   //    slow=slow->next;
   //     fast=fast->next->next;
   // }
   // node *tmp=reverse(slow->next); 
 
    while(A && tmp)
    {
        if(A->val!=tmp->val) return 0;
        A=A->next;
        tmp=tmp->next;
       
    }
    return 1;
}
```

#### Merge two sorted lists
```
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) 
{
    if(A==NULL) return B;
    if( B==NULL) return A;
    
    node *dum=(node *)malloc(sizeof(node));
    node *t;
    t=NULL;
    dum->next=NULL;
    t=dum;
    
    while(A && B )
    {
        if(A->val < B->val)
        {
            t->next=A;
            A=A->next;
        }
        else
        {
            t->next=B;
            B=B->next;
        }
        t=t->next;
    }
    while(A)
    {
        t->next=A;
            A=A->next;
            t=t->next;
    }
    while(B)
    {
        t->next=B;
            B=B->next;
            t=t->next;
    }
    return dum->next;   
}
```

#### Remove Nth Node from List End
```

ListNode* Solution::removeNthFromEnd(ListNode* A, int B) 
{
    if(B==0 || A==NULL  ) return A;
    if(A->next==NULL  && B==1) return NULL;
    
    node *h1=(node *)malloc(sizeof(node));
    node *h2=(node *)malloc(sizeof(node));
    
    h1=A;h2=A;
    
    for(int i=0;i<B ;i++)
    {
        if(h1->next==NULL)
        return A->next;
        h1=h1->next;
        
    }
    while(h1->next!=NULL)
    {
        h1=h1->next;
        h2=h2->next;
    }
    h2->next=h2->next->next;
    return A;
    
}

```

#### Remove Duplicates from Sorted List

Given 1->1->2, return 1->2.

Given 1->1->2->3->3, return 1->2->3.
```
ListNode* Solution::deleteDuplicates(ListNode* A) 
{
    node *tmp=(node *)malloc(sizeof(node));
    tmp=A;
    while(tmp)
    {
        if(tmp->next && tmp->val==tmp->next->val )
        tmp->next=tmp->next->next;
        else
        tmp=tmp->next;
    }
    return A;
}

```

#### Remove Duplicates from Sorted List II
Given 1->2->3->3->4->4->5, return 1->2->5.

Given 1->1->1->2->3, return 2->3.
```
ListNode* Solution::deleteDuplicates(ListNode* A) 
{
    if(!A || !A->next) return A;
    node *dum=new node(0);
    dum->next=A;
    node *prev=dum;
    while(A)
    {
        while(A->next && A->val==A->next->val)
        A=A->next;
        
        if(prev->next==A)
        prev=prev->next;
        else
        prev->next=A->next;
        
        A=A->next;
    }
    return dum->next;
}
```

#### Partition List

Given 1->4->3->2->5->2 and x = 3,

return 1->2->2->4->3->5.
```
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode* temp1=new ListNode(0);
    ListNode* temp2=new ListNode(0);
    
    ListNode *start1=temp1,*start2=temp2;
    
    while(A){
        
        if(A->val<B){
            
                start1->next=A;
                A=A->next;
                start1=start1->next;
            
        }
        else {
                start2->next=A;
                A=A->next;
                start2=start2->next;
        }
   }
    start1->next=temp2->next;
    start2->next=NULL;
    return temp1->next;
        
}
```
#### K reverse linked list
Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5
```
 #define node ListNode
 node* reverse(node *head,  int k)
 {
     node *q=head;
     node *p=NULL,*r=NULL;
     int c=0;
    //leetcode soln: dont reverse a group of less than  k
    // for(int i =0; i < k && t; i++)
    //     {
    //         t = t->next;
    //         c++;
    //     }
    // if(c < k)
    //     return head;
     while(q && c<k)
    {
        r=q->next;
        q->next=p;
        p=q;
        q=r;
    }
    if(q)
    {
         head->next=reverse(q,k);
    }
    return p;
   
 }
ListNode* Solution::reverseList(ListNode* A, int B) 
{
    if(!A || !A->next) return A;
    return reverse(A,B);
}
```
#### Swap List Nodes in pairs
Given 1->2->3->4, you should return the list as 2->1->4->3. Swap adjacent nodes.
```
ListNode* Solution::swapPairs(ListNode* A) 
{
    if(!A || !A->next) return A;
    node *p=A;
   
    while(p  && p->next)
    {
        swap(p->val,p->next->val);
        if(p==NULL || p->next==NULL) 
        break;
        p=p->next->next;
    }
    return A;
}

```
#### Even Reverse
```
ListNode* Solution::solve(ListNode* a) {
    ListNode* p=a;
    int m=1;
    stack<int>s;
    while(1){
        // cout<<m<<" ";
        if(m%2==0)s.push(p->val);
        // cout<<p->val<<" ";
        if(p->next==NULL) break;
        p=p->next;m++;
    }
    // while(!s.empty())cout<<s.top(),s.pop();
    p=a;m=1;
    while(1){
        if(m%2==0){
            p->val=s.top();s.pop();
        }
        if(p->next==NULL)break;
        p=p->next;m++;
    }
    return a;
}
```

#### Rotate List
```
#define listnode ListNode 
ListNode* Solution::rotateRight(ListNode* A, int B) {
    int n = 0;
    listnode* head = A;

    while(head!=NULL)
    {
        n++;
        head = (*head).next;
    }
    B = B%n;
    
    if(B==n || B==0)
        return A;
        
    listnode* l2 = A;
    for(int i=1;i<(n-B);i++)
    {
        l2 = (*l2).next;
    }
    listnode *dum = new ListNode(0);
    dum->next = l2->next;
    l2->next=NULL;
    ListNode *t =dum->next;
    while(t->next)
    t=t->next;
    t->next=A;
    return dum->next;
}

```

#### Intersection of Linked Lists
```
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
  if(A==NULL || B==NULL)
  return NULL;
  ListNode *s=A;
  ListNode *t=B;
  while(s!=t){
      if(s==NULL){
          s=B;
      }
      else
        s=s->next;
    if(t==NULL)
        t=A;
    else
        t=t->next;
  }
  return s;
}
------------------------------------------------------------------------
class Solution {
    public:
        int getLength(ListNode *head) {
            int ret = 0;
            while (head) {
                ret++;
                head = head->next;
            }
            return ret;
        }

        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if(!headA || !headB)
                return NULL;
            int lenA = getLength(headA), lenB = getLength(headB);
            int lenDiff = lenA - lenB;
            ListNode *pa = headA;
            ListNode *pb = headB;
            if(lenDiff > 0) {
                while(lenDiff != 0) {
                    pa = pa->next;
                    lenDiff--;
                }
            }
            else if(lenDiff < 0) {
                while(lenDiff != 0) {
                    pb = pb->next;
                    lenDiff++;
                }
            }
            while(pa && pb) {
                if(pa == pb)
                    return pa;
                pa = pa->next;
                pb = pb->next;
            }
            return NULL;
        }
};
```

#### Merge Sort
```
void MergeSort(Node** headRef)
{
	Node* head = *headRef;
	Node* a;
	Node* b;
	if ((head == NULL) || (head->next == NULL)) {
		return;
	}
	FrontBackSplit(head, &a, &b);
	MergeSort(&a);
	MergeSort(&b);
	*headRef = SortedMerge(a, b);
}

Node* SortedMerge(Node* a, Node* b)
{
	Node* result = NULL;

	/* Base cases */
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);

	/* Pick either a or b, and recur */
	if (a->data <= b->data) {
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else {
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return (result);
}

void FrontBackSplit(Node* source,
					Node** frontRef, Node** backRef)
{
	Node* fast;
	Node* slow;
	slow = source;
	fast = source->next;

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	/* 'slow' is before the midpoint in the list, so split it in two
	at that point. */
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}
-------------------------------------------------------------------------------------------------

Node *merge(Node *firstNode,Node *secondNode) {
	Node *merged = new Node;
	Node *temp = new Node;
	
	//merged is equal to temp so in the end we have the top Node.
	merged = temp;

	//while either firstNode or secondNode becomes NULL
	while(firstNode != NULL && secondNode != NULL) {
	
		if(firstNode->data<=secondNode->data) {
			temp->next = firstNode;
			firstNode = firstNode->next;
		}
		
		else {
			temp->next = secondNode;
			secondNode = secondNode->next;
		}
		temp = temp->next;
	}
	
//any remaining Node in firstNode or secondNode gets inserted in the temp List
	while(firstNode!=NULL) {
		temp->next = firstNode;
		firstNode = firstNode->next;
		temp = temp->next;
	}

	while(secondNode!=NULL) {
		temp->next = secondNode;
		secondNode = secondNode->next;
		temp = temp->next;
	}
	//return the head of the sorted list
	return merged->next;
}

//function to calculate the middle Element
Node *middle(Node *head) {
	Node *slow = head;
	Node *fast = head->next;
	
	while(slow->next != NULL && (fast!=NULL && fast->next!=NULL)) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

//function to sort the given list
Node *sort(Node *head){
	
	if(head->next == NULL) {
		return head;
	}

	Node *mid = new Node;
	Node *head2 = new Node;
	mid = middle(head);
	head2 = mid->next;
	mid->next = NULL;
	//recursive call to sort() hence diving our problem, and then merging the solution
	Node *finalhead = merge(sort(head),sort(head2));
	return finalhead;
}

```

#### Swap kth node from start with kth node from end
However there are some corner cases, which must be handled 
  
    X is next to Y
    
    Y is next to X
    
    X and Y are same
    
    X and Y don’t exist (k is more than number of nodes in linked list)
    
```
int countNodes(struct Node* s)
{
    int count = 0;
    while (s != NULL) {
        count++;
        s = s->next;
    }
    return count;
}
 
/* Function for swapping kth nodes
   from both ends of linked list */
void swapKth(struct Node** head_ref, int k)
{
    // Count nodes in linked list
    int n = countNodes(*head_ref);
 
    // Check if k is valid
    if (n < k)
        return;
 
    // If x (kth node from start) and
    // y(kth node from end) are same
    if (2 * k - 1 == n)
        return;
 
    // Find the kth node from the beginning of
    // the linked list. We also find
    // previous of kth node because we
    // need to update next pointer of
    // the previous.
    Node* x = *head_ref;
    Node* x_prev = NULL;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }
 
    // Similarly, find the kth node from
    // end and its previous. kth node
    // from end is (n-k+1)th node from beginning
    Node* y = *head_ref;
    Node* y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++) {
        y_prev = y;
        y = y->next;
    }
 
    // If x_prev exists, then new next of
    // it will be y. Consider the case
    // when y->next is x, in this case,
    // x_prev and y are same. So the statement
    // "x_prev->next = y" creates a self loop.
    // This self loop will be broken
    // when we change y->next.
    if (x_prev)
        x_prev->next = y;
 
    // Same thing applies to y_prev
    if (y_prev)
        y_prev->next = x;
 
    // Swap next pointers of x and y.
    // These statements also break self
    // loop if x->next is y or y->next is x
    Node* temp = x->next;
    x->next = y->next;
    y->next = temp;
 
    // Change head pointers when k is 1 or n
    if (k == 1)
        *head_ref = y;
    if (k == n)
        *head_ref = x;
}
```
#### Skip M delete N nodes
Input:  M = 3, N = 2

Linked List: 1->2->3->4->5->6->7->8->9->10

Output:  Linked List: 1->2->3->6->7->8
```
void skipMdeleteN(Node *head, int M, int N)
{
    Node *curr = head, *t;
    int count;
 
    // The main loop that traverses
    // through the whole list
    while (curr)
    {
        // Skip M nodes
        for (count = 1; count < M &&
                curr!= NULL; count++)
            curr = curr->next;
 
        // If we reached end of list, then return
        if (curr == NULL)
            return;
 
        // Start from next node and delete N nodes
        t = curr->next;
        for (count = 1; count<=N && t!= NULL; count++)
        {
            Node *temp = t;
            t = t->next;
            free(temp);
        }
         
        // Link the previous list with remaining nodes
        curr->next = t;
 
        // Set current pointer for next iteration
        curr = t;
    }
}
```
#### Flattening a Linked List
```
Node merge(Node a, Node b)
    {
        // if first linked list is empty then second
        // is the answer
        if (a == null)     return b;
  
        // if second linked list is empty then first
        // is the result
        if (b == null)      return a;
  
        // compare the data members of the two linked lists
        // and put the larger one in the result
        Node result;
  
        if (a.data < b.data)
        {
            result = a;
            result.down =  merge(a.down, b);
        }
  
        else
        {
            result = b;
            result.down = merge(a, b.down);
        }
  
        result.right = null; 
        return result;
    }
  
    Node flatten(Node root)
    {
        // Base Cases
        if (root == null || root.right == null)
            return root;
  
        // recur for list on right
        root.right = flatten(root.right);
  
        // now merge
        root = merge(root, root.right);
  
        // return the root
        // it will be in turn merged with its left
        return root;
    }
```

#### Merge a linked list into another linked list at alternate positions
```
void merge(Node *p, Node **q)
{
    Node *p_curr = p, *q_curr = *q;
    Node *p_next, *q_next;
 
    // While therre are avialable positions in p
    while (p_curr != NULL && q_curr != NULL)
    {
        // Save next pointers
        p_next = p_curr->next;
        q_next = q_curr->next;
 
        // Make q_curr as next of p_curr
        q_curr->next = p_next; // Change next pointer of q_curr
        p_curr->next = q_curr; // Change next pointer of p_curr
 
        // Update current pointers for next iteration
        p_curr = p_next;
        q_curr = q_next;
    }
 
    *q = q_curr; // Update head pointer of second list
}
```
#### Merge k sorted lists
[Heap approach](https://github.com/dateduker/Codes/blob/main/Heaps-and-maps.md#user-content-merge-k-sorted-lists)
```
ListNode* Solution::mergeKLists(vector<ListNode*> &A) 
{
    if(A.size()==0) return NULL;
    if( A.size()==1) return   A[0]; 
    
    int n=A.size();
    int k=1;
    while(k<n)
    {
        for(int i=0;i+k<n;i=i+2*k)
        {
            A[i]=merge(A[i],A[i+k]);
        }
        k*=2;
    }
    return A[0];
}
```
