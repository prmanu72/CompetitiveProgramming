#### I. Can reach last index?
Input: nums = [2,3,1,1,4],  Output: true

Input: nums = [3,2,1,0,4],  Output: false

```
bool canJump(vector<int>& nums) {
        int limit = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++)
        {
            if(limit == 0)
                return 0;
            limit = max(limit - 1, nums[i]);
        }
        return 1;
    }
```
#### II. Minimum number of jumps to reach last index
Input: nums = [2,3,1,1,4] Output: 2

Input: nums = [2,3,0,1,4] Output: 2
```
int jump(vector<int>& a) {
        int n = a.size();
        
        int dp[n];
        
        memset(dp, INT_MAX, sizeof dp);
        
        dp[n-1] = 0;
        
        for(int i = n-2; i >= 0; i--){
            int mn = 100000;
            for(int k = 1; k <= a[i] && i+k < n; k++){
                mn = min(mn, dp[i+k]);
            }
            dp[i] = mn + 1;
        }
        return dp[0];
  }
  ----------------------------------------------------------------------------------------
  int jump(vector<int>& nums) {
        int jumps,steps,maxreach;
        jumps=1;
        steps=nums[0];
        maxreach=nums[0];
        
        int n=nums.size();
        if(nums[0]==0) return 0;
        if(n==1 ) return 0;
        for(int i=1;i<n-1;i++)
        {
            maxreach=max(maxreach,nums[i]+i);
            steps--;
            if(steps==0)
            {
                jumps++;
                if(i>maxreach) return INT_MAX;
                steps=maxreach-i;
            }
        }
        return jumps;
    }
```

