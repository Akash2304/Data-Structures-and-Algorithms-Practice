/*********************************************************************************************************************************************************************

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
