1. [Rain water trapping I](#user-content-rain-water-trapping-i)
2. [Balanced paranthesis](#user-content-balanced-paranthesis)
3. [Redundant brackets](#user-content-redundant-brackets)
4. [Min stack O(n) space](#user-content-min-stack-on-space)
5. [Min stack (1) space](#user-content-min-stack-o1-space)
6. [Evaluate Expression](#user-content-evaluate-expression)

#### Rain water trapping I
Make two arrays lmax[i] = max heaight in left, rmax[i] = max height in right
```
int lmax[n];
lmax[0] = a[0];
for(int i = 0;i < n; i++)
{
  lmax[i] = max(a[i], lmax[i-1]);
}
```
#### Balanced paranthesis
```
int Solution::solve(string A) 
{
    stack<int> s;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='(')
        {
            s.push(i);
        }
        else
        {
            if(s.empty())
            {
                return 0;
            }
            s.pop();
        }
    }
    return s.empty();
    
}
```
#### Redundant brackets
For redundancy two condition will arise while popping- 
 
If immediate pop hits an open parenthesis ‘(‘, then we have found a duplicate parenthesis. For example, (((a+b))+c) has duplicate brackets around a+b. When we reach second “)” after a+b, we have “((” in the stack. Since the top of stack is an opening bracket, we conclude that there are duplicate brackets. 

If immediate pop doesn’t hit any operand(‘*’, ‘+’, ‘/’, ‘-‘) then it indicates the presence of unwanted brackets surrounded by expression. For instance, (a)+b contain unwanted () around a thus it is redundant. 
    
```
int Solution::braces(string A) 
 {
    stack<char> s;
    for(int i=0;A[i];i++)
    {
        if(A[i]==')')
        {
            int c=0;
            char top=s.top();
            s.pop();
            while(!s.empty() && top!='(')
            {
                top=s.top();
                s.pop();
                c++;
            }
            if(c==0) return 1;
        }
        else if(A[i]=='+' || A[i]=='-' || A[i]=='*' || A[i]=='/' || A[i]=='(')
        s.push(A[i]);
    }
    return 0;
}
-----------------------------------------------------------------------------------------------
bool checkRedundancy(string& str)
{
    // create a stack of characters
    stack<char> st;
 
    // Iterate through the given expression
    for (auto& ch : str) {
 
        // if current character is close parenthesis ')'
        if (ch == ')') {
            char top = st.top();
            st.pop();
 
            // If immediate pop have open parenthesis '('
            // duplicate brackets found
            bool flag = true;
 
            while (!st.empty() and top != '(') {
 
                // Check for operators in expression
                if (top == '+' || top == '-' ||
                    top == '*' || top == '/')
                    flag = false;
 
                // Fetch top element of stack
                top = st.top();
                st.pop();
            }
 
            // If operators not found
            if (flag == true)
                return true;
        }
 
        else
            st.push(ch); // push open parenthesis '(',
                  // operators and operands to stack
    }
    return false;
}
```
#### Min stack O(1) space
```
  stack<int> s;
  int minEle=0;

MinStack::MinStack() 
{
    s=stack<int>();
    minEle=0;    
}

void MinStack::push(int x) 
{
    if(s.empty())
	{
		s.push(x);
		minEle=x;
	}
	else if(x>=minEle)
		s.push(x);
	else // x < minEle , push flag
	{
		s.push(2*x-minEle);
		minEle=x;
	}
	return;
}

void MinStack::pop() 
{
    int k;
	if(s.empty())
		return ;  //-1 or anything mentioned 
	if(s.top()>=minEle)
	{
		k=s.top();
		s.pop();
		return ;
	}
	else if(s.top()<minEle)
		{
			k=minEle;
			minEle=2*minEle-s.top();
			s.pop();
			return ;
		}
}

int MinStack::top() 
{
    if(s.empty()) return -1;
    else
    {
        if(s.top()>=minEle)
        return s.top();
        else
        return minEle;
    }
}

int MinStack::getMin() 
{
    if(s.empty())
		return -1;

	return minEle;
}
```
#### Min stack in O(n) space
```
stack<int> s,ss;
MinStack::MinStack() {
	s = stack<int>();
	ss = stack<int>();
}

void MinStack::push(int x) {
	if(ss.empty() || ss.top() >= x)
	ss.push(x);
	s.push(x);
}

void MinStack::pop() {
	if(s.empty()) return;
	if(ss.top() == s.top()) 
	ss.pop();
	s.pop();
}

int MinStack::top() {
	if(s.empty()) return -1;
	return s.top();
}

int MinStack::getMin() {
	if(ss.empty()) return -1;
	return ss.top();
}
```
#### Evaluate Expression
```
bool sign(string c)
{
    if(c=="+" || c=="-" || c=="*" || c=="/")
    return true;
    return false;
}
int Solution::evalRPN(vector<string> &A) 
{
    stack<int> s;
    int ans=0;
    int n=A.size();
    //if(n<3) return 0;
    for(int i=0;i<n;i++)
    {
        if(sign(A[i]))
        {
            ans=0;
            int op2=s.top();
            s.pop();
            int op1=s.top();
            s.pop();
            
            if(A[i]=="+")
            ans+=(op1+op2);
            if(A[i]=="-")
            ans+=(op1-op2);
            if(A[i]=="*")
            ans+=(op1*op2);
            if(A[i]=="/")
            ans+=(op1/op2);
            s.push(ans);
            //cout<<ans<<" ";
        }
        else
        s.push(stoi(A[i]));
    }
    return s.top();
}
```
