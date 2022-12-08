class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        //create adjacency list for all bombs
        vector<vector<int>> adj(bombs.size());
        for(int i=0; i<bombs.size(); i++)
        {
            for(int j=0; j<bombs.size(); j++)
            {
                if(i!=j)
                {
                    if(in_range(bombs, i, j))
                    {
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int ans = 0;
        // perform bfs considering every bomb as source , find the max ans
        for(int i=0; i<bombs.size(); i++)
        {
            int x = bfs(i, bombs.size(), adj);
            ans = max(ans, x);
        }
        
        return ans;
    }

    bool in_range(vector<vector<int>>& bombs, int i, int j) {
        float distance = sqrt( pow (bombs[i][0] - bombs[j][0], 2) + pow(bombs[i][1] - bombs[j][1], 2));
        if ( distance <= bombs[i][2] || distance <= bombs[j][2] ) {
            return true;
        }
        return false;
    }
    
    int bfs(int bid, int len, vector<vector<int>> adj)
    {
        int val = 1;
        vector<int> blasted(len, 0);
        queue<int> q;
        q.push(bid);
        blasted[bid]=1;
        int blastedTillNow = 1;
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            for(auto k : adj[f])
            {
                if(!blasted[k])
                {
                    q.push(k);
                    blasted[k]=1;
                    blastedTillNow++;
                    val = max(val, blastedTillNow);
                }
            }
        }
        return val;
    }
};
