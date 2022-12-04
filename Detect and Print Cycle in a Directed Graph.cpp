//// Question Detect and Print Cycle in a Directed Graph.
//// If there is no cycle present, return -1.

/// Code Starts:
#include <bits/stdc++.h>

using namespace std();


bool checkDFS(int node , vector<int> adj[], vector<int> &vis, vector<int> &DFSvis, vector<int> &cycle){
        vis[node] = 1;
        DFSvis[node] = 1;
        for (auto it: adj[node]){
            if (!vis[it]){
                if(checkDFS(it,adj,vis,DFSvis,cycle)){
                    cycle.push_back(it);
                    return true;
                }
            }
            else if(DFSvis[it]){
                cycle.push_back(it);
                return true;
            }
        }
        DFSvis[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> cycle;
        vector<int> vis(V,0);
        vector<int> DFSvis(V,0);
        for (int i=0;i<V;i++){
            if (!vis[i]){
                checkDFS(i,adj,vis,DFSvis, cycle);
            }
        }
        int x = 0;
        for (int i = 1;i<cycle.size();i++){
            if (cycle[i] == cycle[0]) {
            x = i; 
            break;
            }
        }
        for (int i = x; i>0;i--){
            cout<<cycle[i];
        }
        
        return false;
    }
  }  
    
    
int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        if (!obj.isCyclic(V, adj)){
          cout << -1;
        }
    }

    return 0;
}
