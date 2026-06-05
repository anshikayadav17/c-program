class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);

        for(auto &x : pre){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }

        queue<int> q;

        for(int i=0;i<n;i++)
            if(indegree[i]==0) q.push(i);

        int cnt=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;

            for(auto it:adj[node]){
                if(--indegree[it]==0)
                    q.push(it);
            }
        }

        return cnt==n;
    }
};
