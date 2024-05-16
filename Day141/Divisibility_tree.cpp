//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    vector<int> sizeOfTree;
    int dfs(vector<vector<int>>& graph, vector<int>& sizeOfTree, vector<bool>& vis, int node) {
        vis[node] = true;
        int size = 1;
        for(auto child: graph[node]) {
            if(vis[child]) continue;
            size += dfs(graph, sizeOfTree, vis, child);
        }
        
        vis[node] = false;
        return sizeOfTree[node] = size;
    }
    
    int dfs(vector<vector<int>>& graph, vector<int>& sizeOfTree, vector<bool>& vis, int node, int total) {
        vis[node] = true;
        int ans = 0;
        for(auto child: graph[node]) {
            if(vis[child]) continue;
            ans += dfs(graph, sizeOfTree, vis, child, total) + (((sizeOfTree[child] % 2 == 0) && ((total - sizeOfTree[child]) % 2 == 0)) ? 1 : 0);
        }
        
        vis[node] = false;
        return ans;
    }
    
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    sizeOfTree.resize(n + 1, 0);
	    vector<vector<int>> graph(n + 1);
	    for(auto edge: edges) {
	        graph[edge[0]].push_back(edge[1]);
	        graph[edge[1]].push_back(edge[0]);
	    }
	    vector<bool> vis(n + 1, false);
	    int total = dfs(graph, sizeOfTree, vis, 1);
	    
	    return dfs(graph, sizeOfTree, vis, 1, total);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends