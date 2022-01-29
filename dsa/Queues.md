1. [Sliding window maximum](#user-content-sliding-window-maximum)
2. [First non-repeating character in a stream of characters](#user-content-first-non-repeating-character-in-a-stream-of-characters)
3. [LRU Cache](#user-content-lru-cache)
  
#### Sliding window maximum
  ```
  vector<int> Solution::slidingMaximum(const vector<int> &A, int B) 
{
    vector<int> v;
    deque<int> q(B);
    int n=A.size();
    if(n==0) return v;
    
    int i;
    for( i=0;i<B;i++)
    {
        while(!q.empty() && A[i]>=A[q.back()])
        q.pop_back();
        q.push_back(i);
    }
    if(i>=n) {
        v.push_back(A[q.front()]);
        return v;
    }
    for(;i<n;i++)
    {
        v.push_back(A[q.front()]);
        while(!q.empty() && q.front()<=i-B)
        q.pop_front();
        while(!q.empty() && A[i]>=A[q.back()])
        q.pop_back();
        q.push_back(i);
    }
    v.push_back(A[q.front()]);
    return v;
}
```
#### First non-repeating character in a stream of characters
```
string Solution::solve(string s) 
{
    string res="";
    if(s.length()==0 || s.length()==1 ) return s;
    queue<char> q;
    vector<int> v(26,0);
    for(int i=0;s[i];i++)
    {
        q.push(s[i]);
        v[s[i]-'a']++;
        while(!q.empty() && v[q.front()-'a']>1)
        q.pop();
        if(q.empty())
        res+='#';
        else
        res+=q.front();
    }
    return res;
}
```

#### LRU Cache
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
