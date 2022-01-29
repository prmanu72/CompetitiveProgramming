1. [Median of 2 Arrays](#user-content-median-of-2-arrays)
2. [Square root of integer](#user-content-square-root-of-integer)
3. [Rotated Sorted Array Search](#user-content-rotated-sorted-array-search)
4. [Matrix Median](#user-content-matrix-median)
5. [Count Element Occurence](#count-element-occurence)


#### Median of 2 Arrays
```
double fun(const vector<int> &a, const vector<int> &b);
double Solution::findMedianSortedArrays(const vector<int> &a, const vector<int> &b) 
{
    if(a.size()>b.size())
    return fun(b,a);
    return fun(a,b);
}
double fun(const vector<int> &a, const vector<int> &b)
{
    int x=a.size(),y=b.size();
    int l=0,h=x;
    while(l<=h)
    {
        int partx=(l+h)/2;
        int party=(x+y+1)/2-partx;
        int maxLeftx=(partx==0)?INT_MIN:a[partx-1];
        int minrightx=(partx==x)?INT_MAX:a[partx];
        
        int maxLefty=(party==0)?INT_MIN:b[party-1];
        int minrighty=(party==y)?INT_MAX:b[party];
        
        if(maxLeftx<=minrighty && maxLefty<=minrightx)
        {
            if((x+y)%2==0)
            return (double)(max(maxLeftx,maxLefty)+min(minrightx,minrighty))/2;
            else
            return (double)max(maxLeftx,maxLefty);
        }
        else if(maxLeftx>minrighty)
        h=partx-1;
        else
        l=partx+1;
        
    }
}
```

#### Square root of integer
```
int Solution::sqrt(int A) {
    if(A==0 || A==1) return A;
    long long  ans=0;
    long long l = 1, r = A, mid;
    while(l<=r)
    {
         mid = (l+r)/2;
        long long sq = mid*mid; 
        if( sq == A) return mid;
        if(sq < A)
        {
            ans=mid;
            l=mid+1;
        }
        else
        r = mid-1;
    }
    return ans;
}
```

#### Rotated Sorted Array Search
```
int bin(const vector<int> &v,int l,int r ,int b);
int Solution::search(const vector<int> &v, int b) 
{
    int r=distance(v.begin(),max_element(v.begin(),v.end()));
    int l1=bin(v,0,r,b);
    int l2=bin(v,r+1,v.size()-1,b);
    if(l1==-1 && l2==-1)
    return -1;
    if(l1==-1)
    return l2;
    else return l1;
}
int bin(const vector<int> &v,int l,int r ,int b)
{
    if(b<v[l] || b>v[r])
    return -1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(v[mid]==b)
        return mid;
        if(v[mid]<b)
        l=mid+1;
        else
        r=mid-1;
    }
    return -1;
}
```

#### Matrix Median
```
int Solution::findMedian(vector<vector<int> > &a) 
{
    int n=a.size(),m=a[0].size();
    int min=INT_MAX,max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i][0]<min) min=a[i][0];
        if(a[i][m-1]>max) max=a[i][m-1];
    }
    int req=(n*m+1)/2;
    while(min<max)
    {
        int mid=min+(max-min)/2;  
        int c=0;
        for(int i=0;i<n;i++)
        c=c+upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();
        
        if(c<req)
        min=mid+1;
        else
        max=mid;
    }
    return min;
}
```
#### Count Element Occurence
```


class Solution {    
    public:
    int findCount(const vector<int> &A, int target) {
        int n = A.size();
        int i = 0, j = n - 1;
        int start = -1, end = -1;

        // FIND FIRST
        while (i < j)
        {
            int mid = (i + j) /2;
            if (A[mid] < target) i = mid + 1;
            else j = mid;
        }
        if (A[i] != target) return 0; // the element does not exist in the array.

        start = i;

        // FINDLAST
        j = n - 1;  // We don't have to set i to 0 the second time.
        while (i < j)
        {
            int mid = (i + j) /2 + 1;   // Make mid biased to the right
            if (A[mid] > target) j = mid - 1;  
            else i = mid;               // So that this won't make the search range stuck.
        }
        end = j;
        return (end - start + 1); 
    }
};

------------------------------------------------------------------------------------------------
int bin_l(const vector<int> &a, int k, int l, int r){
    int ans = -1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(a[mid] == k){
            ans = mid;
            r = mid - 1;
        }
        else if (a[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return ans;
}
int bin_r(const vector<int> &a, int k, int l, int r){
    int ans = -1;
    while(l <= r){
        int mid = l + (r-l)/2;
        if(a[mid] == k){
            ans = mid;
            l = mid + 1;
        }
        else if (a[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return ans;
}
int Solution::findCount(const vector<int> &a, int k) 
{
    int n = a.size();
    if(n == 1){
        if(a[0] == k) return 1;
        else return 0;
    }
    int l = 0, r = n-1;
    int start = -1, end = -1;
    while(l <= r){
        int m = l + (r - l)/2;
        if(a[m] == k){
            start = bin_l(a,k,l, m-1);
            end = bin_r(a, k, m, r);
            if(start == -1) return end - m + 1;
            
            return end-start+1;
        }
        else if(a[m] < k)
        l = m+1;
        else
        r = m-1;
    }
    
    return 0;
}
```
