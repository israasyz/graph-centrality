#include<iostream>
#include<functional>
#include <utility>
#include<iomanip>
#include<list>
#include<queue>
#include<iterator>
#include<vector>
#include<iostream>
using namespace std;
 
# define INF 0x3f3f3f3f 
  
typedef pair<int, int> iPair; 
  
void addEdge(list< pair<int, int> > *adj,int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 
  
int shortestPath(list< pair<int, int> > *adj,int src, int V)
{     
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 
    int sum_pathes=0;
    
    vector<int> dist(V, INF); 
   
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop(); 
  
        // 'i' is used to get all adjacent vertices of a vertex 
        list< pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent 
            // of u. 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            //  If there is shorted path to v through u. 
            if (dist[v] > dist[u] + weight) 
            { 
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
    //sum of shortest pathes from src to all other vertices  
    for (int i = 0; i < V; i++) 
        sum_pathes+= dist[i]; 
    
    return sum_pathes;
} 
  
int main() 
{   
    int n, m, u, v, w;
    list< pair<int, int> > *adj; 
    double *closeness;
    cin>>n>>m;
    
    adj = new list<iPair> [n]; 
    closeness = new double [n];
    
    for (int i=0; i<m; i++) 
    {   
        cin>>u>>v>>w;
        addEdge(adj,u, v, w); 
    } 
    
    for (int i=0; i<n; i++) 
    { 
      int sum = shortestPath(adj,i,n); 
      closeness[i] = (double)(n-1)/(double)sum;
      cout<<fixed<<setprecision(12)<<closeness[i]<<'\n';
    }  
  
    return 0; 
} 
