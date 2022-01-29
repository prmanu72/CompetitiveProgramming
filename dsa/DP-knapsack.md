### [Unbounded Knapsack](#unbounded-knapsack-1)
### 01 Knapsack
#### Recursive
```
int KnapsackRecur(int Val[],int Wt[],int cap, int n)
{
	if(n==0 || cap ==0)
		return 0;
	if(Wt[n-1]<=cap)
		return max(Val[n-1]+KnapsackRecur(Val,Wt,cap-Wt[n-1],n-1) ,  KnapsackRecur(Val,Wt,cap,n-1));
	else
		return KnapsackRecur(Val,Wt,cap,n-1);
}
```

#### Memoize
```
static int t[n+1][cap+1];
memset(t,-1,sizeof(t));
int KnapsackRecur(int Val[],int Wt[],int cap, int n)
{
	if(n==0 || cap ==0)
		return 0;
	if(t[n][cap]!=-1)
		return t[n][cap];
	else if(Wt[n-1]<=cap)
		return t[n][cap]=max(Val[n-1]+KnapsackRecur(Val,Wt,cap-Wt[n-1],n-1),KnapsackRecur(Val,Wt,cap,n-1));
	else
		return t[n][cap]=KnapsackRecur(Val,Wt,cap,n-1);
}
```

#### Top-down
```
int KnapsackTopDown(int val[],int wt[],int cap, int n)
{
	int i,j;
	int t[n+1][cap+1];
	for( i=0;i<=cap;i++)
		t[0][i]=0;
	for( i=0;i<=n;i++)
		t[i][0]=0;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=cap;j++)
		{
			if(wt[i-1]<=j)
				t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
			else
				t[i][j]=t[i-1][j];
		}
	}
	return t[n][w];
}
```

#### Subset-sum
```
bool SubsetSum(int arr[],int sum, int n)
{
	int i,j;
	bool t[n+1][sum+1];
	for( i=1;i<=sum;i++)
		t[0][i]=false;
	for( i=0;i<=n;i++)
		t[i][0]=true;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=cap;j++)
		{
			if(arr[i-1]<=j)
				t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
			else
				t[i][j]=t[i-1][j];
		}
	}
	return t[n][sum];
}
```

#### Equal-sum-partition
* subsetSum(arr,sumOfArr/2,size)

#### Count-number-of-subsets-with-a-given-sum
```
int CountSubsets(int arr[],int sum, int n)
{
	int i,j;
	bool t[n+1][sum+1];
	for( i=1;i<=sum;i++)
		t[0][i]=0;
	for( i=0;i<=n;i++)
		t[i][0]=1;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=cap;j++)
		{
			if(arr[i-1]<=j)
				t[i][j]=t[i-1][j]+t[i-1][j-arr[i-1]];
			else
				t[i][j]=t[i-1][j];
		}
	}
	return t[n][sum];
}
```

#### Minimum-subset-sum-difference
min(s1-s2)

s2 = sum - s1

-> min(2s1-sum)

If s1<sum/2 -> min(sum-2s1)
```
int findMin(int arr[], int n) 
{ 
    int sum = 0;  
    for (int i = 0; i < n; i++) 
        sum += arr[i]; 

   bool dp[n+1][sum+1]; 
   
    for (int i = 0; i <= n; i++) 
        dp[i][0] = true; 
  
     
    for (int i = 1; i <= sum; i++) 
        dp[0][i] = false; 
  
    for (int i=1; i<=n; i++) 
    { 
        for (int j=1; j<=sum; j++) 
        { 
            // If i'th element is excluded 
            dp[i][j] = dp[i-1][j]; 
  
            // If i'th element is included 
            if (arr[i-1] <= j) 
                dp[i][j] ||= dp[i-1][j-arr[i-1]]; 
        } 
    } 
    
    int diff = INT_MAX; 
      
 
    for (int j=sum/2; j>=0; j--) 
    { 
 
        if (dp[n][j] == true) 
        { 
            diff = sum-2*j; 
            break; 
        } 
    } 
    return diff; 
} 
```
#### Count the number of subset with a given difference
solve(arr[], diff, n)

sum = sum(arr)

Required: s1 - s2 = diff

But,      s1 + s2 = sum

Implies, s1 = (diff + sum)/2

return [NoOfSubsetsWithGivenSum(s1)](#count-number-of-subsets-with-a-given-sum)

#### Target-sum
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".

Return the number of different expressions that you can build, which evaluates to target.

* Similar to [Count the number of subset with a given difference](#count-the-number-of-subset-with-a-given-difference), where diff = target sum


### Unbounded Knapsack
```
int unboundedKnapsack(int wt[],int val[],int cap, int size)
{
	int i,j;
	int t[n+1][cap+1];
	for( i=0;i<=cap;i++)
		t[0][i]=0;
	for( i=0;i<=n;i++)
		t[i][0]=0;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=cap;j++)
		{
			if(wt[i-1]<=j)
			{
				t[i][j]=max(val[i-1]+t[i][j-wt[i-1]], t[i-1][j]);
			}
			else
				t[i][j]=t[i-1][j];
		}
	}
	return t[n][w];
}
```

#### Rod-cutting
```
int rodCutting(int len[],int price[],int cap, int size)
{
	int i,j;
	int t[n+1][cap+1];
	for( i=0;i<=cap;i++)
		t[0][i]=0;
	for( i=0;i<=n;i++)
		t[i][0]=0;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=cap;j++)
		{
			if(len[i-1]<=j)
			{
				t[i][j]=max(price[i-1]+t[i][j-len[i-1]], t[i-1][j]);
			}
			else
				t[i][j]=t[i-1][j];
		}
	}
	return t[n][cap];
}
```

#### Coin change I
* Max number of ways to make given sum
* Similar to count no. of subsets with given sum

#### Coin change II
* Min number of coins to make a given sum
```
int coinChange(int arr[],int cap, int size)
{
	...
	...
	initialize 1st row as INT_MAX-1
	1st column as 0
	2nd row as t[i][j]=j/arr[0];
		for(j=1;i<=sum;i++)
			if(j % arr[0] == 0)
				t[1][j] = j/arr[0];
			else
				t[1][j] = INT_MAX-1;		
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(wt[i-1]<=j)
			{
			t[i][j]=min(t[i][j-arr[i-1]]+1,t[i-1][j]);
			}
			else
			t[i][j]=t[i-1][j];
		}
	}
	
}
```
