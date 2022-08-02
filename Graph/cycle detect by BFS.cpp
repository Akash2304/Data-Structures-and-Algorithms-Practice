/*********************************************************************************************************************************************************************
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 
Example 1:
Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
Output: 1
Explanation: 
1->2->3->4->1 is a cycle.
Example 2:
Input: 
V = 4, E = 2
adj = {{}, {2}, {1, 3}, {2}}
Output: 0
Explanation: 
No cycle in the graph.
 
Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number
of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not,
return 1 if a cycle is present else return 0.
NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.
 
Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)
*********************************************************************************************************************************************************************/
bool cycleBfs(int s,vector<int>adj[],vector<int>&vis){
        queue<pair<int,int>>q;
        q.push({s,-1});
        vis[s]=1;
        while(!q.empty()){
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push({it,node});
                    vis[it]=1;
                }
                else if(it!=par)
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cycleBfs(i,adj,vis))
                return true;
            }
        }
        return false;
    }
