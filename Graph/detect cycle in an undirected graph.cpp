/********************************************************************************************************************************************************************
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
bool cycle(vector<int>adj[],int s,bool visited[],int parent)
    {
        visited[s]=true;
        for(auto u:adj[s])
        {
            if(visited[u]==false)
            {
                if(cycle(adj,u,visited,s)==1)
                return 1;
                
                else if(u!=parent)
                return 1;
            }
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        bool visited[V+1];
        for(int i=0;i<V;i++)
        visited[i]=false;
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                if(cycle(adj,i,visited,-1)==1)
                return 1;
            }
        }
        return 0;
    }
};
