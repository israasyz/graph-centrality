*Closeness Algorithm*
```
Algortihm: Sequential algorithm for computing closeness centrality in a weighted graph using Dijkstra's algorithm
```
```
Input: Graph G, a weight function c(u, v) returning 
the weight of an edge from u → v and a starting vertex S
Output: ∀ v reachable from S, dist[u] is set to the distance from S to v

function dijkstra(G, s):
1  ∀ t ∈ V : dist[t] ← ∞;
2  ∀ t ∈ V : prev[t] = null; // Initialize previous pointers to null
3  dist[s] ← 0; // Initialize distance decorations
4  P Q ← empty priority queue which returns
   elements in non-decreasing order by dist;
5  while PQ not empty do
6  | dequeue v ← P Q;
7  | foreach neighbor w of v do	//each edge coming out of u
8  | | if dist[v] + c(v, w) < dist[w] then
9  | | | dist[w] = dist[v] + c(v, w);
10 | | | w.prev = v // Maintain pointers for path
11 | | | enqueue w → P Q;
   | | |_
   | |_
   |_
 
12 n ← number of vertices V of graph G
13 foreach s ∈ V do
14 | sum ← dijkstra(G, s):
15 | CC[s] = (n-1)/sum;
   |_
   
```
*Betweeness Algorithm* 
```
Algorithm: Sequential algorithm for computing betweenness centrality in a weighted graph using
Brandes’ technique for aggregating dependencies [1]
```
```
Input: Graph G, a weight function c(u, v) returning
the weight of an edge from u → v
Output: ∀ v ∈ V : CB[v] the betweenness centrality
1  ∀ v ∈ V : CB(v) = 0;
2  foreach s ∈ V do
3  | S ← empty stack;
4  | ∀ w ∈ V : P[w] ← empty list;
5  | ∀ t ∈ V : σ[t] ← 0; σ[s] ← 1;
6  | ∀ t ∈ V : dist[t] ← ∞; dist[s] ← 0;
7  | P Q ← empty priority queue which returns
   | elements in non-decreasing order by dist;
8  | enqueue s → P Q;
9  | while P Q not empty do
10 | | dequeue v ← P Q;
11 | | push v → S;
12 | | foreach neighbor w of v do
13 | | | if dist[v] + c(v, w) < dist[w] then
14 | | | | dist[w] = dist[v] + c(v, w);
15 | | | | enqueue w → P Q;
   | | | |_
16 | | | if dist[w] = dist[v] + c(v, w) then
17 | | | | σ[w] ← σ[w] + σ[v];
18 | | | | append v → P[w];
   | | | |_
   | | |_
   | |_
19 | ∀ w ∈ V : δ[v] ← 0;
20 | while S not empty do
21 | | pop w ← S;
22 | | foreach v ∈ P[w] do
23 | | | δ[v] ← δ[v] + σ[v]/σ[w]· (1 + δ[w]);
   | | |_
24 | | if w ≠ s then CB[w] ← CB[w] + δ[w];  
   | |_
   |_
```
References
------------------
[1] Nick Edmonds, Torsten Hoefler, and Andrew Lumsdaine: A Space-Efficient Parallel Algorithm for Computing Betweenness Centrality in Distributed Memory.
