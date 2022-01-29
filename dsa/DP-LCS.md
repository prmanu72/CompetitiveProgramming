#### Recursive
```
int LCSrecursive(string x, string y, int m, int n)
{
	if(n==0 || m==0)
		return 0;
	if(x[m-1]==y[n-1])
		return 1+ LCSrecursive(x,y,m-1,n-1);
	else
		return max(LCSrecursive(x,y,m,n-1),LCSrecursive(x,y,m-1,n));
}
```

#### Memoize
```
int t[1001][1001];

int LCSmemoize(string x, string y,int m, int n)
{
	memset(t,-1,sizeof(t));

	if(m==0 || n==0)
		return 0;
	if(t[m][n]!=-1)
		return t[m][n];

	if(x[m-1]==y[n-1])
		return t[m][n]=1+LCSmemoize(x,y,m-1,n-1);
	else
		return t[m][n]=max(LCSmemoize(x,y,m-1,n),LCSmemoize(x,y,m,n-1));
}
```

#### Bottom-up
```
int LCStopDown(string x, string y, int m, int n)
{
	int t[m+1][n+1];
	memset(t,-1,sizeof(t));
	int i,j;

	for(i=0;i<=n;i++)
		t[0][i]=0;
	for(i=0;i<=m;i++)
		t[i][0]=0;

	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
				{
					t[i][j]=1+t[i-1][j-1];
				}
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	}
	
	return t[m][n];
}
```

#### Print lcs
```
int printlcs(string x, string y, int m, int n)
{
	int t[m+1][n+1];
	memset(t,-1,sizeof t);
	int i,j;

	for(i=0;i<=n;i++)
		t[0][i]=0;
	for(i=0;i<=m;i++)
		t[i][0]=0;

	string s="";
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
				{
					t[i][j]=1+t[i-1][j-1];
				}
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	}
	
  i=m,j=n;
	while(i>0 && j>0){
	    if(x[i-1]==y[j-1])
			{
				s=x[i-1]+s;
				i--;j--;
			}
			else if(t[i-1][j] == t[i][j])
			i--;
			else if(t[i][j-1] == t[i][j])
			j--;
	}
			
	
 	cout<<s;
	return t[m][n];
}
```

#### Shortest common super-sequence 
* find LCS of two strings ,return length (x)+ length (y)-length(LCS) 

#### Print SCS
```
#include <bits/stdc++.h>
using namespace std;
void PrintSCS(string x, string y, int m, int n)
{
	int t[m+1][n+1];
	memset(t,-1,sizeof(t));
	int i,j;

	for(i=0;i<=n;i++)
		t[0][i]=0;
	for(i=0;i<=m;i++)
		t[i][0]=0;

	string s="";
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
				{
					t[i][j]=1+t[i-1][j-1];
				}
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	}
	i=m,j=n;
	while(i>0 && j>0)
		{
			if(x[i-1]==y[j-1])
			{
			
				s=x[i-1]+s;
				i--;j--;
			}
			else if(t[i-1][j] == t[i][j])
			{
			
			s=x[i-1]+s;
				i--;
			}	
			else if(t[i][j-1] == t[i][j])
			{
				s=y[j-1]+s;
				j--;
			}	
		}
	
	cout<<s; // prints "acbcdaf"
	return ;
}
int main() {
	PrintSCS("abcdaf","acbcf",6,5);
	
	return 0;
}
```

#### Minimum Number of Insertion and Deletion to convert String a to String b 
* No. of Deletion: len(a) - len(lcs)
* No. of insertion: len(b) - len(lcs)

#### Longest palindromic subsequence 
* find LCS of given string and its reversal
```
int longestPlainSubseq(string s){
	return len(lcs(s, reverse(s));
}
------------------------------------------------------------------------------
// A Dynamic Programming based C++ program for LPS problem
// Returns the length of the longest palindromic subsequence in seq
#include<stdio.h>
#include<string.h>

// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }

// Returns the length of the longest palindromic subsequence in seq
int lps(char *str)
{
int n = strlen(str);
int i, j, cl;
int L[n][n]; // Create a table to store results of subproblems


for (i = 0; i < n; i++)
	L[i][i] = 1;
	for (cl=2; cl<=n; cl++)
	{
		for (i=0; i<n-cl+1; i++)
		{
			j = i+cl-1;
			if (str[i] == str[j] && cl == 2)
			L[i][j] = 2;
			else if (str[i] == str[j])
			L[i][j] = L[i+1][j-1] + 2;
			else
			L[i][j] = max(L[i][j-1], L[i+1][j]);
		}
	}

	return L[0][n-1];
}

/* Driver program to test above functions */
int main()
{
	char seq[] = "GEEKS FOR GEEKS";
	int n = strlen(seq);
	printf ("The length of the LPS is %d", lps(seq));
	getchar();
	return 0;
}

```
#### Longest Palindromic Substring
```
#include <bits/stdc++.h>
using namespace std;
int longestPalSubstr(string str)
{
	// get length of input string
	int n = str.size();

	// table[i][j] will be false if substring
	// str[i..j] is not palindrome.
	// Else table[i][j] will be true
	bool table[n][n];

	memset(table, 0, sizeof(table));

	// All substrings of length 1
	// are palindromes
	int maxLength = 1;

	for (int i = 0; i < n; ++i)
		table[i][i] = true;

	// check for sub-string of length 2.
	int start = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (str[i] == str[i + 1]) {
			table[i][i + 1] = true;
			start = i;
			maxLength = 2;
		}
	}

	// Check for lengths greater than 2.
	// k is length of substring
	for (int k = 3; k <= n; ++k) {
		// Fix the starting index
		for (int i = 0; i < n - k + 1; ++i) {
			// Get the ending index of substring from
			// starting index i and length k
			int j = i + k - 1;

			// checking for sub-string from ith index to
			// jth index iff str[i+1] to str[j-1] is a
			// palindrome
			if (table[i + 1][j - 1] && str[i] == str[j]) {
				table[i][j] = true;

				if (k > maxLength) {
					start = i;
					maxLength = k;
				}
			}
		}
	}

	cout << "Longest palindrome substring is: ";
	printSubStr(str, start, start + maxLength - 1);

	// return length of LPS
	return maxLength;
}

// Driver Code
int main()
{
	string str = "forgeeksskeegfor";
	cout << "\nLength is: "
		<< longestPalSubstr(str);
	return 0;
}

```

#### Minimum number of deletion in a string s to make it a palindrome
* No. of deletion: len(s) - LCS(s, rev(s))
* Minimum no. of insertion to make it a palindrome = No of deletion

#### Edit distance
string x = "horse" to y = "ros" ; N = NULL
```
  N h o r s e
N 0 1 2 3 4 5 
r 1 1 2 2 3 4 
o 2 2 1 2 3 4 
s 3 3 2 2 2 3 
```
```
t[i][j] = t[i-1][j-1] + 1 => replace x[j-1] to  y[i-1]

	= t[i-1][j] + 1 =>  inserting y[i-1]
	
	= t[i][j-1] + 1 => deleting x[j-1]
```
```
int minDistance(string x, string y) {
        int n1 = x.size(), n2 = y.size();
        int t[n2+1][n1+1];
        memset(t, 0, sizeof t);
        
        for(int i = 0; i <= n1; i++)
            t[0][i] = i;
        for(int i = 0; i <= n2; i++)
            t[i][0] = i;
	    
         for(int i = 1; i <= n2; i++){
            for(int j = 1; j <= n1; j++){
                if(x[j-1] == y[i-1])
                    t[i][j] = t[i-1][j-1];
                else{
                    int tmp = min(t[i-1][j], t[i][j-1]);
                    t[i][j] = min(t[i-1][j-1], tmp) + 1;
                }
                    
            }
        }
        
        return t[n2][n1];
    }
```

#### Longest repeating subsequence
```
#include <bits/stdc++.h>
using namespace std;
int mnb(string x, string y, int m, int n)
{
	int t[m+1][n+1];
	memset(t,-1,sizeof(t));
	int i,j;

	for(i=0;i<=n;i++)
		t[0][i]=0;
	for(i=0;i<=m;i++)
		t[i][0]=0;

	string s="";
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1] && i!=j)
				{
					t[i][j]=1+t[i-1][j-1];
					if(s.back() != x[i-1])
					s+=x[i-1];
				}
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
		}
	}
	cout<<s<<endl; // prints abd
	return t[m][n];
}
int main() {
	cout<< mnb("aabebcdd","aabebcdd", 8, 8); // 3
	return 0;
}
```

####  Sequence Pattern Matching
* Check if a string a is subsequence of string b
* return len(a) == lcs(a,b);
