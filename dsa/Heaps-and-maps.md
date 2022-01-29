Maxheap
```
priority_queue<type> maxheap;
```

Minheap
```
priority_queue< type, vector<type>, greater<type> > minheap;
```
1. [Rain water trapping II](#user-content-rain-water-trapping-ii)
2. [Distinct Numbers in Window](#user-content-distinct-numbers-in-window)
3. [Merge k sorted lists](#user-content-merge-k-sorted-lists)
4. [LRU Cache](#user-content-lru-cache)
5. [Distinct Numbers in Window](#user-content-distinct-numbers-in-window)
6. [Maximum Sum Combinations](#user-content-maximum-sum-combinations)
7. [K Largest Elements](#user-content-k-largest-elements)

#### Rain water trapping II
[Explanation](https://www.youtube.com/watch?v=QvQiQcLCQ4Y)
```
#define type pair<int,pair<int,int> > 
class Solution {
public:
    int trapRainWater(vector<vector<int>>& grid) {
        
        int r = grid.size(), c = grid[0].size();
        
        vector< vector<int> > vis(r, vector<int>(c,0));
        
        priority_queue<type, vector<type>, greater<type> > pq;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i==0 || j == 0 || i == r-1 || j == c-1)
                    {
                    pq.push({grid[i][j], {i,j}});
                    vis[i][j]=true;
                    }
            }
        }
        
        int minbdht = 0, vol = 0;
        
        while(!pq.empty())
        {
            int curht = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            minbdht = max(minbdht, curht);
            pq.pop();
            
            int rdir[] = {0,0,1,-1};
            int cdir[] = {1,-1,0,0};
            
            for(int p = 0;p<4;p++)
            {
                int tr = i+rdir[p];
                int tc = j+cdir[p];
                if(tr >= 0 && tc >= 0 && tr < r && tc < c && vis[tr][tc] == false){
                    vis[tr][tc] = true;
                    pq.push({ grid[tr][tc],{tr,tc}});
                    if(minbdht > grid[tr][tc])
                        vol+=(minbdht-grid[tr][tc]);
                }
            }
        }
        return vol;        
    }
};
```
#### Distinct Numbers in Window
Input 1:
 A = [1, 2, 1, 3, 4, 3]
 B = 3

Input 2:
 A = [1, 1, 2, 2]
 B = 1

Output 1:
 [2, 3, 3, 2]

Output 2:
 [1, 1, 1, 1]


```
vector<int> Solution::dNums(vector<int> &A, int B) 
{
    map<int,int> mp;
    int i=0;
    for(;i<B;i++)
    {
        mp[A[i]]++;
    }
    vector<int> res(A.size()-B+1);
    if(i==A.size())
    {
        res[0]=mp.size();
        return res;
    }
    res[0]=mp.size();
    int k;
    for( i=1,k=B;k<A.size();k++,i++)
    {
        mp[A[k]]++;
        mp[A[k-B]]--;
        if( mp[A[k-B]]==0)
        mp.erase(A[k-B]);
        res[i]=mp.size();
    }
    return res;
}
```
####  Merge k sorted lists
```
       struct CompareNode {
                bool operator()(ListNode* const & p1, ListNode* const & p2) {
                        // return "true" if "p1" is ordered before "p2", for example:
                        return p1->val > p2->val;
                }
        };

    ListNode* Solution::mergeKLists(vector<ListNode *> &lists) {
            ListNode* dummy = new ListNode(0);
            ListNode* tail = dummy;

            priority_queue<ListNode*,vector<ListNode*>,CompareNode> queue;

            for (int i = 0; i < lists.size(); i++) {
                    if (lists[i] != NULL) {
                            queue.push(lists[i]);
                    }
            }

            while (!queue.empty()) {
                    tail->next = queue.top();
                    queue.pop();
                    tail = tail->next;

                    if (tail->next) {
                            queue.push(tail->next);
                    }
            }

            return dummy->next;
    } 
```

##### LRU Cache
```
#include<bits/stdc++.h>
using namespace std;
list<pair<int,int>> dq;

unordered_map<int,list<pair<int,int>>::iterator> mp;
int mx=0;
LRUCache::LRUCache(int capacity) 
{
    dq.clear();
    mx=capacity;
    mp.clear();
}

int LRUCache::get(int key) {
    if(mp.find(key)==mp.end())
    return -1;
    
    auto it=mp[key];
    int val=it->second;
    dq.erase(it);
    dq.push_front({key,val});
    mp[key]=dq.begin();
    return val;
}

void LRUCache::set(int key, int value) 
{
    if(mp.find(key)==mp.end())
    {
        if(dq.size()==mx)
        {
            auto it=dq.back();
            int k=it.first;
            dq.pop_back();
            mp.erase(k);
        }
    }
    else
    {
        auto iter=mp[key];
        dq.erase(iter);
    }
    dq.push_front({key,value});
    mp[key]=dq.begin();
}
```

#### Distinct Numbers in Window
```
vector<int> Solution::dNums(vector<int> &A, int B) 
{
    map<int,int> mp;
    int i=0;
    for(;i<B;i++)
    {
        mp[A[i]]++;
    }
    vector<int> res(A.size()-B+1);
    if(i==A.size())
    {
        res[0]=mp.size();
        return res;
    }
    res[0]=mp.size();
    int k;
    for( i=1,k=B;k<A.size();k++,i++)
    {
        mp[A[k]]++;
        mp[A[k-B]]--;
        if( mp[A[k-B]]==0)
        mp.erase(A[k-B]);
        res[i]=mp.size();
    }
    return res;
}
```

#### Maximum Sum Combinations
```
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    priority_queue<pair<int,pair<int,int>>> heap;
    vector<int> ans;
    set<pair<int,int>> s;
    int n = A.size();
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    // push last(greatest) numbers sum and indices in heap
    // kind of like an initialisation for the heap
    heap.push(make_pair(A[n-1]+B[n-1],make_pair(n-1,n-1)));
    
    while(C--){
        pair<int,pair<int,int>> temp = heap.top();
        heap.pop();
        
        ans.push_back(temp.first);
        
        int x = temp.second.first;
        int y = temp.second.second;
        
        int sum = A[x-1]+A[y];
        
        pair<int,int> temp1 = make_pair(x-1,y);
        
        // if the pair of indices x-1 and y is not present in the set,
        // push this sum and pair of indices into the heap and set
        if(s.find(temp1)==s.end()){
            heap.push(make_pair(sum,temp1));
            s.insert(temp1);
        }
        
        sum = A[x]+A[y-1];
        temp1 = make_pair(x,y-1);
        
        // if the pair of indices x and y-1 is not present in the set,
        // push this sum and pair of indices into the heap and set
        if(s.find(temp1)==s.end()){
            heap.push(make_pair(sum,temp1));
            s.insert(temp1);
        }
    }
    
    return ans;
}
```

#### K Largest Elements
```
vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue<int> heap;
    vector<int> ans;
    for(int i:A)
    heap.push(i);
    while(B-- && !heap.empty())
    {
        ans.push_back(heap.top());
        heap.pop();
    }
    return ans;
}
```
