class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();

        vector<vector<pair<int,int>>> adj(n);

        for(auto &edge: edges){//To construct the graph
            int u = edge[0], v = edge[1];
            adj[u].push_back({v,vals[v]});
            adj[v].push_back({u,vals[u]});
        }

        int maximum = INT_MIN;

        for(int node=0;node<n;node++){
            vector<int> connectedNodeValue;

            for(auto &neighbor:adj[node]){
                connectedNodeValue.push_back(neighbor.second);
            }

            sort(connectedNodeValue.begin(),connectedNodeValue.end(),greater<int>());

            int sum = vals[node];

            maximum = max(maximum,sum);

            for(int i=0;i<connectedNodeValue.size() && i<k;i++){
                sum+=connectedNodeValue[i];
                maximum = max(maximum,sum);
            }
        }
        return maximum;
    }
};
