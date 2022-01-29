Component
* In a component every vertex is reached from any other vertex

Cycle in directed graph
* There is a path between every two nodes

#### Topological sort | DFS
* Condition1: exists for Directed Acyclic Graph (DAG) only
* Condition2: There has to be atleast one node with indegree 0 and one node with out degree 0

```
void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int>& Stack)
{
    // Mark the current node as visited.
    visited[v] = true;
  
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
  
    // Push current vertex to stack which stores result
    Stack.push(v);
}
  
// The function to do Topological Sort. It uses recursive
// topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> Stack;
  
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
  
    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
  
    // Print contents of stack
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}
```



#### Topological sort | BFS | Kahn's Algorithm
```
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> topo(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    vector<int> topo
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        topo.push_back(node)
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    return topo;
	}
};
int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
```

#### Cycle detection
```
//using dfs for Directed graph 
/*
the approach used in undirected graph wont work here, bcoz it returns true for 1->2<-3 but there is no cycle here
so, here we use recursion stack
we mark a vertex as true in while exploring its children and after exploring we maark in as false
*/
bool cyclicUtil(vector<int> adj[],vector<bool> &visited,vector<bool> &recst,int u)
{
    visited[u]=true;
    recst[u]=true;
    
    for(auto it: adj[u])
    {
        if(visited[it]==false)
        {
            if(cyclicUtil(adj,visited,recst,it))
            return true;
        }
        else if(recst[it]==true)
        return true;
    }
    recst[u]=false;
    return false;
}
bool isCyclic(int v, vector<int> adj[])
{
    vector<bool> visited(v,0),recst(v,0);
    
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            if(cyclicUtil(adj,visited,recst,i))
            return true;
        }
    }
    return false;
}


//using dfs for undirected graph
//O(v+e)

bool cyclicUtil(vector<int> adj[],vector<bool> &visited,int u,int parent)
{
    visited[u]=true;
    for(auto it:adj[u])
    {
        if(visited[it]==false ) 
        {
           if( cyclicUtil(adj,visited,it,u))
                return true;
        }
        else if( it!=parent)
        return true;
    }
    return false;
}

bool isCyclic(vector<int> adj[], int v)
{
   vector<bool> visited(v,false);
   
   for(int i=0;i<v;i++)
   {
       if(visited[i]==false)
            if(cyclicUtil(adj,visited,i,-1)==true)
                return true;
   }
   return false;
}
------------------Detect cycle in an undirected graph using BFS ---------------------
bool isCyclicConntected(vector<int> adj[], int s,
                        int V, vector<bool>& visited)
{
    // Set parent vertex for every vertex as -1.
    vector<int> parent(V, -1);
 
    // Create a queue for BFS
    queue<int> q;
 
    // Mark the current node as
    // visited and enqueue it
    visited[s] = true;
    q.push(s);
 
    while (!q.empty()) {
 
        // Dequeue a vertex from queue and print it
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                parent[v] = u;
            }
            else if (parent[u] != v)
                return true;
        }
    }
    return false;
}
 
bool isCyclicDisconntected(vector<int> adj[], int V)
{
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);
 
    for (int i = 0; i < V; i++)
        if (!visited[i] && isCyclicConntected(adj, i,
                                         V, visited))
            return true;
    return false;
}
```                     
#### Cycle detection | Kahn's Algorithm
* Condition2(There has to be atleast one node with indegree 0 and one node with out degree 0) fails for cyclic graph after removing certain nodes

![cyclicgraph](https://user-images.githubusercontent.com/70789919/128804734-28874594-2048-4778-b07e-a57caf824d9f.png)

```
	bool isCyclic(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    int cnt = 0;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        cnt++; 
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    if(cnt == N) return false; 
	    return true; 
	}
```
#### Prim's algorithm
```
#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
	int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    // Run the loop till all the nodes have been visited
    // because in the brute code we checked for mstSet[node] == false while computing the minimum
    // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
    // hence its better to keep running till all the nodes have been taken. 
    // try the following case: 
    // Credits: Srejan Bera
    // 6 7 
    // 0 1 5 
    // 0 2 10 
    // 0 3 100 
    // 1 3 50 
    // 1 4 200
    // 3 4 250
    // 4 5 50 

    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
		key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}
-----------------------Brute -----------------
#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
	int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
  

    key[0] = 0; 
    parent[0] = -1; 
    int ansWeight = 0;
    for (int count = 0; count < N - 1; count++)
    { 
        
        int mini = INT_MAX, u; 
  
        for (int v = 0; v < N; v++) 
            if (mstSet[v] == false && key[v] < mini) 
                mini = key[v], u = v; 
                
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) 
                parent[v] = u, key[v] = weight; 
        }
            
    } 
    
    
    for (int i = 1; i < N; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}
```
#### Krushkal 
```
// There are numerous classic approaches for finding Minimum Spanning Tree(MST) of a graph. One among them is Kruskal’s method.
// Kruskal’s Algorithm builds the spanning tree by adding edges one by one into a growing spanning tree. 
// Kruskal’s algorithm follows greedy approach as in each iteration it finds an edge which has least weight and add it 
// to the growing spanning tree.

// Steps:
//     Sort the graph edges with respect to their weights.
//     Start adding edges to the MST from the edge with the smallest weight until the edge of the largest weight.
//     Only add edges which doesn’t form a cycle , edges which connect only disconnected components.

// So now the question is how to check if vertices are connected or not ?

// We can find it using Disjoint sets method. Disjoint sets are sets whose intersection is the empty set, 
// so it means that they don’t have any element in common.

// See author’s solution for more details.

#define N 100005

int n,m,p[N],rank11[N];
vector<pair<int, pair<int, int> > > v;

void create_set() {
    for(int i = 1; i <= n; i++) {
        p[i] = i,rank11[i] = 0;
    }
}

int find_set(int u) {
    int x = p[u];
    if(x != u)
        x = find_set(x);
    return x;
}
void merge_set(int u, int v) {
    int s1 = find_set(u);
    int s2 = find_set(v);
    if(rank11[s1] > rank11[s2])
        p[s2] = s1;
    else 
        p[s1] = s2;
    if(rank11[s1] == rank11[s2])
        rank11[s2] += 1;
}
int kruskal() {
    create_set();
    int res = 0;
    for(int  i = 0; i < v.size(); i++) {
        int v1 = v[i].second.first;
        int v2 = v[i].second.second;
        if(find_set(v1) != find_set(v2)) {
            res += v[i].first;
            merge_set(v1,v2);
        }
    }
    return res;
}


int Solution::solve(int A, vector<vector<int> > &B) {
	n = A;
	m = (int)B.size();
	v.clear();
	for (int i = 0; i < m; i++) {
		int x,y, cost;
		x = B[i][0];
		y = B[i][1];
		cost = B[i][2];
		v.push_back(make_pair(cost,make_pair(x,y)));
	}
	sort(v.begin(),v.end());
	return kruskal();
}
```

#### Shortest path from source to every other vertex | Undirected | unweighted graph
```
void BFS(vector<int> adj[], int N, int src) 
{ 
	int dist[N];
	for(int i = 0;i<N;i++) dist[i] = INT_MAX; 
	queue<int>  q;
	
	dist[src] = 0;
	q.push(src); 

	while(q.empty()==false) 
	{ 
		int node = q.front(); 
		q.pop();
		 
		for(auto it:adj[node]){
		    if(dist[node] + 1 < dist[it]){
		        dist[it]=dist[node]+1;
		        q.push(it);
		    }
		} 
	} 
	for(int i = 0;i<N;i++) cout << dist[i] << " "; 	
} 
```

#### Shortest path from source to every other vertex | DAG | weighted graph | Topological sort
```
* Lets say we want to do it using DFS

yes you can do it using DFS , but consider the case when you already updated a node's distance by a dfs() call and lets say its 7 

and as it is DFS then its obvious that you also have  updated all the nodes in its segment of DFS call . now you have reached to 

the same node from different dfs() call and now the distance is 4 , so in order to update all the nodes  which were affected by 

the DFS call previously on the node considering distance as 7 , you now again have to do the same so that its updated with new 

min distance. Same is the scenario for the simple BFS approach. This multiple time calling DFS/BFS degrades the Time Complexity, 

hence Topological Ordering save you from that overhead as you already know which nodes will come after the current node , so you 

keep on updating it .

* if (dist[node] != INF) This condition is also used because all other nodes whose in-degree is also zero, cannot be reached 

   from source node
```

```
#include <bits/stdc++.h> 
#define INF INT_MAX 
using namespace std; 

void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int,int>> adj[]) {
    vis[node] = 1; 
    for(auto it : adj[node]) {
        if(!vis[it.first]) {
            findTopoSort(it.first, vis, st, adj); 
        }
    }
    st.push(node);
}


void shortestPath(int src, int N, vector<pair<int,int>> adj[]) 
{ 
	int vis[N] = {0};
	stack<int> st; 
	for (int i = 0; i < N; i++) 
		if (!vis[i]) 
			findTopoSort(i, vis, st, adj); 
			
	int dist[N]; 
	for (int i = 0; i < N; i++) 
		dist[i] = 1e9; 
	dist[src] = 0; 

	while(!st.empty()) 
	{  
		int node = st.top(); 
		st.pop(); 
 
		if (dist[node] != INF) {
		    for(auto it : adj[node]) {
		        if(dist[node] + it.second < dist[it.first]) {
		            dist[it.first] = dist[node] + it.second; 
		        }
		    }
		}
	} 

	for (int i = 0; i < N; i++) 
		(dist[i] == 1e9)? cout << "INF ": cout << dist[i] << " "; 
} 

int main() 
{ 
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v, wt;
	    cin >> u >> v >> wt; 
	    adj[u].push_back({v, wt}); 
	}
	
	shortestPath(0, n, adj); 

	return 0; 
} 
```

#### Shortest path from source to every other vertex | Djistra's Algorithm | Directed & undirected | Non-negative weighted graph  | Greedy
* Time: O((|V| + |E|) log V)
* Space: O(|V| + |E|)
```
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,source;
	cin >> n >> m;
	vector<pair<int,int> > g[n+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		g[a].push_back(make_pair(b,wt));
		g[b].push_back(make_pair(a,wt));
	}	
	
	cin >> source;
	
	// Dijkstra's algorithm begins from here
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
	vector<int> distTo(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths; 
	
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)
	
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
		
	}
	
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	
	return 0;
}
```
#### Word search board
```
int Solution::exist(vector<string> &A, string B) {
    int n = A.size();
    int m = A[0].size();

    // [i, r, c]  
    stack<array<int, 3>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == B[0])
                q.push({0, i, j});
        }
    }

    while (!q.empty()) {
        auto [i, r, c] = q.top();
        //cout << i << " " << r << " " << c << endl;
        q.pop();

        if (i == B.length())
            return true;
        
        if (A[r][c] == B[i]) {
            if (r > 0)
                q.push({i+1, r-1, c});
            
            if (r < n-1)
                q.push({i+1, r+1, c});

            if (c > 0)
                q.push({i+1, r, c-1});
            
            if (c < m-1)
                q.push({i+1, r, c+1});
        }

    }

    return false;
}
```

#### Valid path
```
/* the idea is to start traversing the rectangle co-ordinates one by one
from each (i,j) i have 8 choices to move , for doing this i will use 
queue and visited array , visited help in reducing same call 
at each (i,j) i will first check wheter the point lies inside any circle or
not by calculating it distance from centre of each circle ,if distance is greater than 
r then point lies outside the circle , after my queue is empty if the (x,y)
co-ordinate is marked as visited means it is possible to reach there */

// these are the moves which i can take from any position i,j 
int dpx[8]={1,1,1,-1,-1,-1,0,0};
int dpy[8]={-1,1,0,1,-1,0,-1,1};

// this function is used to check wheter the i,j column lies inside the rectangle or not
bool valid(int x,int y,int A,int B){
    if(x<0||x>A||y<0||y>B){
        return false;
    }
    return true;
}

// this function check wheter the point x,y lies inside any circle or not
bool inCircle(int x,int y,int C,int D,vector<int>&E,vector<int>&F){
    for(int i=0;i<C;i++){
        if(((x-E[i])*(x-E[i])+(y-F[i])*(y-F[i]))<=(D*D))
         return true;
    }
    return false;
}

// A,B = x,y ; C = n, D = r;  E,F= x,y coordinates
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
          // visited array
          bool vis[A+1][B+1];
          memset(vis,false,sizeof(vis));
          queue<pair<int,int>> myque;
          myque.push({0,0});
          vis[0][0]=true;
          // first checking wheter the point (0,0) lies in circle or not
          if(inCircle(0,0,C,D,E,F))
           return "NO";
          
          
          while(myque.size()){
              // pick first element of queue
              pair<int,int> temp=myque.front();
              myque.pop();
              // checking all 8 possible moves
              for(int i=0;i<8;i++){
                  int a=temp.first+dpx[i];
                  int b=temp.second+dpy[i];
                  if(!vis[a][b]&&valid(a,b,A,B)&&!inCircle(a,b,C,D,E,F)){
                     
                      myque.push({a,b});
                      vis[a][b]=true;
                  }
              }
          } 
          if(vis[A][B])
          return "YES";
          else
          return "NO";
}
```

#### Snake Ladder Problem
```
int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    unordered_map<int,int> ladder,snakes;
    for(auto v: A)
        ladder.insert({v[0],v[1]});
    for(auto v: B)
        snakes.insert({v[0],v[1]});
    queue<pair<int,int>> q;
    vector<bool> visited(101,false);
    q.push({1,0});
    visited[1] = true;
    while(!q.empty()){
        auto ele = q.front();
        q.pop();
        if(ele.first==100)
            return ele.second;
        for(int k =1; k<=6; k++){
            int pos = ele.first+k;
            if(ladder.find(pos) != ladder.end())
                pos = ladder[pos];
            if(snakes.find(pos) != snakes.end())
                pos = snakes[pos];
            if(!visited[pos]){
                visited[pos] = true;
                q.push({pos,ele.second+1});
            }
        }
    }
    return -1;
}
```
#### Bi partite graph
* An undirected graph with odd cycle cannot be a bipartite graph
```
-------check if a graph is bipartite  using bfs------------
bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
    queue<int>q;
    q.push(src); 
    color[src] = 1; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; 
                q.push(it); 
            } else if(color[it] == color[node]) {
                return false; 
            }
        }
    }
    return true; 
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            if(!bipartiteBfs(i, adj, color)) {
                return false;
            }
        }
    }
    return true; 
}
-------check if a graph is bipartite  using dfs------------
bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
    for(auto it : adj[node]) {
        if(color[it] == -1) {
            color[it] = 1 - color[node];
            if(!bipartiteDfs(it, adj, color)) {
                return false; 
            }
        } else if(color[it] == color[node]) return false; 
    }
    return true; 
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            color[i] = 1;
            if(!bipartiteDfs(i, adj, color)) {
                return false;
            }
        } 
    }
    return true; 
}
```
