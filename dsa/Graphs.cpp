GRAPHS

Algorithms
Prims - minimum spanning tree
Krushkal - minimum spanning tree
Djikstra - min dist of all vertices from a given source(directed and undirected) O(vlogv)
Bellman Ford algorithm - min dist of vertices from given src O(VE)
Khans - uses indegree of vertices, topological sort and cycle detection(directed graph)
kosaraju - to find cut vertices uses 2 dfs traversals
Tarzan

no of Verticies O(logE)
no of Edges O(v ^ 2)

-------------- -SPANNING TREES------------------------------

A ST of n vertices has v - 1 edges
No of spanning trees
for complete graph :
no of Spanning trees of n Verticies is n^(n - 2)
for non complete graph :
	Kirchoffs algorithm
	make adjacency matrix for given graph
1 : change diagonal elements (0 s) to degree of that vertex
2 : change non diagonal 1s to - 1
3 : find cofactor of any element of resultant matrix
Prims algorithm :
			Always forms trees
			cycles arent formed
			O(v ^ 2)	//arrays
			O(vlogv + elogv + e) = O(ElogV) // min heap
			                       O(ElogV + E) // fibonacci heap
		{for dense graph : O(v ^ 2) is best, for sparse : O(ElogV)}
Krushkals algorithm:
a chance of forming forests
cycles can be formed

minimum spanning tree: Krushkal O(ElogE + v + E*α(v)) : space: O(v)
	struct edge
{
	int src, dst, wt;
	edge(int s, int d, int w)
	{
		src = s; dst = d; wt = w;
	}
	bool operator<(edge const& other) {
		return wt < other.wt;
	}
};
vector<int> parent[v], rank[v];
int Krushkal(edge arr[])
{
	sort(arr)//O(ElogE)
	int res = 0;
	for (int i = 0; i < v; i++) //O(V)
	{
		parent[i] = i;
		rank[i] = 0;
	}
	for (int i = 0, s = 0; s < v - 1; i++) //O(E)
	{
		edge e = arr[i];
		int x = find(e.src);
		int y = find(e.dst);
		if (x != y)
		{
			res += e.wt;
			union(x, y);
			s++;
		}
	}
	return res;
}
-------------- -Applications-------------------------- -
DFS:
1. Cycle detection
2. Topological sorting [make file utility in software]
3. Stringly connected components[kosaraju, tarzan s algo]
4. Solving problems like maze or puzzles
5. Path finding
BFS:
1. Search bar in social media platforms
2. Shortest path algo
3. Crawler in search engine
4. Peer to peer networks
5. Garbage collection
6. Cycle detection
7. Ford Fulkerson algo
8. Broadcasting

-------------- -Topological sort: only for directed acyclic graph------------------------------
#for undirected graph there are no dependencies as in directed graph

### khan s algorithm using indegree of vertices and queue o(v+e)
make an array of indegree of vertices
create a queue q
enqueue all vertices with indegree  0
while q isnt empty
	pop and print top elemnt u(say)
		decrese indegree of its vertices by 1
		if indegree is 0 then enqueue it
### Using DFS:
		crete stack stk
	{
		visited[], vector<int> adj[], int v
			/ for (int i = 0; i < v; i++)
			{
				if (visited[i] == false)
					dfs(adj[], stk, visited, i)
				}
			while (stk.empty() == false)
				print stk elements
			}
dfs()
{
	visited[i] = true
	             for (int i = 0; i < adj[u]; i++)
		             if (visited[i] == false) dfs()

			             stk.push(u)
		}

-------------- -CYCLE DETECTION: ---------------------------------- -
### khans algorithm: undirected
use topoloical sorting algorithm:
with variable count = 0:
                      while printing elements increase count value

                      at the end if count != V , then cycle is detected
### dfs: directed(rec stk) & undirected(parent)

------------------------------ -SHORTEST PATH----------------------------------
### topoloical sort for DAG
	                      dist[v] = {inf, inf, inf, ..., inf}
		                                dist[src] = 0
		                                        for every vertex u in topoloical sort
		                                        for node v adjacent nodes of u
			                                        if (dist[v] > dist[u] + wt(uv))
					                                        dist[v] = dist[u] + wt(uv)

### Djikstra s algorithm for undirected/directed weighted graph:  doesnt work for negative weighted graph
					                                                bcz if there is a cycle of negative edges then min dist can go to - INF

					 Djikstra(source) O(vlogv + ElogE) == O(vlogv)
					{
						create a minheap;
						vector<int> dist(v, INT_MAX);
						dist[source] = 0;

						push all dist elements into minheap

						while (minheap != empty)
						{
							u = extract min;
							relax all adjacent of u that are not in heap
						}

					}
relax(u, v)
{
	d[v] > d[u] + wt[uv]
	d[v] = d[u] + wt[uv]
}

### Bellman Ford algorithm:
: works for negative weighted edges topoloical
: uses dynamic programming
: can report negative cycles
O(VE)
	dist[v] = {inf, inf, inf, ..., inf}
	          dist[src] = 0
	                      for (int i = 0; i < v - 1; i++)
		                      for all edges(any order) in the graph
			                      relax(u, v)
#after v-1 iterations all dist must be min, after this iteration
			                      if we get a min dist than prev then, there is a negative cycle
			                      //detect negative cycle
			                      for all edges in graph
				                      if d[v] < d[u] + wt[uv]
						                      "there is a negative cycle"


-------------- -CONNECTED COMPONENTS: -------------------------------- -
#for undirected graph just find bfs/dfs to find connected components

### kosaraju algorithm: for directed graph
						                      make a dfs traversal and store elements in stack (as in topological sort)
						                      elements in stack are in decreasing order of finish time(top of stack has max finish time)
						                      reverse the edges
						                      make a dfs traversal starting from top elements of stack
						                      print dfs traversal
						                      for next element if not visited, make dfs traversal
							                      each time a traversal is made is of a connected component

                      Articulaton point:
							                      in tree structure of dfs
							                      1. if root has two children then it is a Articulaton point
								                      2. u -> v if low[v] >= disc[u] then u is Articulaton point
                      disc: discovery time : time taken to reach tha node
                      low value: node that can be reached with min disc time
                      Bridge:
                      u -> v: if low[v] > disc[u], then uv is a bridge

                      Tarzan s algorithm for strongly connected components : (better than kosaraju s since only one traversal)
								mark low time and disc time
								make a dfs tree, while traversing push elements into stack
								for every node whose children are explored and its low time == disc time, [happens after exploring leaves in dfs]
									then pop elements from stack till this node including it(popped elements are a connected component)
