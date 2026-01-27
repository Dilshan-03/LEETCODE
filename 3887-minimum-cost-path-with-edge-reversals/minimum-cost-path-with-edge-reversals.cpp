class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<int> dist(n , 1e9);
        vector<vector<pair<int , int>>> adjList(n);
        //Construct adjList
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] , v = edges[i][1] , wt = edges[i][2];
            adjList[u].push_back({v , wt});
            adjList[v].push_back({u , 2 * wt});
        }
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> minHeap;
        minHeap.push({0 , 0});
        dist[0] = 0;
        while(!minHeap.empty()){
            auto it = minHeap.top();
            minHeap.pop();
            int node = it.second , cost = it.first;
            for(auto it : adjList[node]){
                int wt = it.second;
                int adjNode = it.first;
                if(wt + cost < dist[adjNode]){
                    dist[adjNode] = wt + cost;
                    minHeap.push({wt + cost , adjNode});
                }
            }
        }
        return (dist[n - 1] == 1e9) ? -1 : dist[n - 1];
    }
};