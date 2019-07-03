#include<iostream>
#include<list>
#include<queue>
#include<iterator>
#include<vector>
#include<iostream>
using namespace std;
 
typedef pair<int, int> iPair; 
 
void addEdge(list< pair<int, int> > *adj,int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 
  
int main() 
{   
    int n, m, u, v, w;
    list< pair<int, int> > *adj; 
    int *degree;
    cin>>n>>m;
    
    adj = new list<iPair> [n]; 
    degree = new int [n];
    
    for (int i=0; i<m; i++) 
    {   
        cin>>u>>v>>w;
        addEdge(adj,u, v, w); 
    } 
    
    for (int i=0; i<n; i++) 
    { 
      int node_edges=0;
      for (list<pair<int,int>>::iterator it=adj[i].begin(); it != adj[i].end(); ++it)
      {
        node_edges++; 
      }
      degree[i]=node_edges;
       cout<<degree[i]<<'\n';
    }  
  
    return 0; 
} 