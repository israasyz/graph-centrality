//#include<bits/stdc++.h> 
#include<iostream>
#include<list>
#include<queue>
#include<stack>
#include<iterator>
#include<vector>

using namespace std;
# define INF 0x3f3f3f3f   
// iPair ==>  Integer Pair 
typedef pair<int, int> iPair; 
  
void addEdge(list< pair<int, int> > *adj,int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 
   
long double * brandes(list< pair<int, int> > *adj,int n){
    /*
     * The main Function, run the Betweenness Centrality based on 
     * Brandes algorithm for the graph and returns a long double array
     */
    int n_nodes = -1, *d = NULL, *sigma = NULL, v = -1, w = -1;
    int i = -1, s = -1;
    long double *delta = NULL;
    long double *Cb = NULL;
    stack<int> S;
    //std::queue<int> Q;
	  priority_queue< iPair, vector <iPair> , greater<iPair> > Q;
    vector< vector<int> > P;

    n_nodes = n;

    sigma = (int*) malloc(n_nodes*sizeof(int));
    delta = (long double*) malloc(n_nodes*sizeof(long double));
    d = (int*) malloc(n_nodes*sizeof(int));
    Cb = (long double*) malloc(n_nodes*sizeof(long double));
    for(i=0; i < n_nodes; i++){
        //for each node i in the graph
        Cb[i] = 0.0;
    }
    for(i=0; i < n_nodes; i++){
        //P is a list of vectors, in this implementation
        //it is a vector of vectors
        P.push_back(vector<int>());
    }
    for(s=0; s < n_nodes; s++){
        //s is the index of the current node

        //empty stack
        while(!(S.empty())){
            S.pop();
        }
        //empty list, for all the nodes in the graph
        for(i=0; i < n_nodes; i++){
            while(!(P[i].empty())){
                P[i].pop_back();
            }
        }
        for(i=0; i < n_nodes; i++){
            //for all the nodes in the graph
            sigma[i] = 0;
            d[i] = INF;
        }
        sigma[s] = 1;
        d[s] = 0;
        //empty queue
        while(!(Q.empty())){
            Q.pop();
        }
        //start by enqueue the node s in Q
        Q.push(make_pair(d[s],s));
        while(!(Q.empty())){
            //dequeue v from Q
            v = Q.top().second;
            
			//.front();
            Q.pop();
            //push v in S
            S.push(v);
            
            //foreach neighbor w of v
	    // 'it' is used to get all adjacent vertices of a vertex 
            list< iPair >::iterator it; 
            for (it = adj[v].begin(); it != adj[v].end(); ++it){ 
		w = (*it).first; 
                int weight = (*it).second;
                
                if(d[w] > ( d[v] + weight)){
			
                    d[w] = d[v] + weight; 
		    //enqueue w in Q	
                    Q.push(make_pair(d[w],w));	
                 }
                //shortest path to w via v?
                if(d[w] == (d[v] + weight)){
			
                    sigma[w] += sigma[v];
                    //append V in P[w]
                    P[w].push_back(v); 
                }
            }
        }
        //delta[v] = 0, for each node in graph
        for(i=0; i < n_nodes; i++){
            delta[i] = 0;
        }
    
        //S retuns vertices in order of non-increaning distance from s
        while(!(S.empty())){
            //pop w from S
            w = S.top();
           
            S.pop();
            //for all nodes in P[w]
            for(vector<int>::size_type j = 0; j != P[w].size(); j++){
           
                delta[P[w][j]] += ((1.0 * sigma[P[w][j]]/sigma[w]) * (1 + delta[w]));
                
            }

            if(w != s){

                Cb[w] += delta[w];
            }
        }
    }
    for(i=0; i < n_nodes; i++){
        //the centrality scores must be divided by two in this case, cause the
        //graph is undirected, since all shortest paths are considered two times
        Cb[i] = Cb[i]/2;
    }
    free(sigma);
    free(delta);
    free(d);
    return Cb;
}
int main()
{
    int n, m, u, v, w;
    list< pair<int, int> > *adj; 
    long double *Cb = NULL;

    cin>>n>>m;
    
    adj = new list<iPair> [n]; 
    
    for (int i=0; i<m; i++) 
    {   
        cin>>u>>v>>w;
        addEdge(adj,u, v, w); 
    } 
    
    
    Cb = brandes(adj,n);

    for(int i=0; i < n; i++){
        printf("%.*Lf\n",12, Cb[i]);
    }
    free(Cb);
    return 0;
}
