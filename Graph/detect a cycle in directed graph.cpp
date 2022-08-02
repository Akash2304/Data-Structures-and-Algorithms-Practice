/*******************************************************************************************************************************************************************
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:



Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:

Input:


Output: 0
Explanation: no cycle in the graph

Your task:
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices
and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 105
**********************************************************************************************************************************************************************/

https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?page=1&category[]=Graph&sortBy=submissions

bool cycle(vector<int>adj[],int s,bool visited[],bool recst[]){
        visited[s]=true;
        recst[s]=true;
        
        for(auto u:adj[s])
        {
            if(visited[u]==false && cycle(adj,u,visited,recst))
            return 1;
            
            else if(recst[u]==true)
            return 1;
        }
        recst[s]=false;
        return 0;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        
        bool visited[V+1];
        bool recst[V+1];
        
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
            recst[i]=false;
        }
        
        for(int i=0;i<V;i++)
        {
            
            if(visited[i]==false){
                if(cycle(adj,i,visited,recst))
                return 1;
            }
        }
        return 0;
    }
