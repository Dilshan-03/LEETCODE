class Solution {
private:
    vector<long long> dijkstra(int src ,vector<vector<pair<int , int>>>& adjList){
        vector<long long> dist(26 , -1);
        priority_queue<pair<long long , int> , vector<pair<long long , int>> , greater<pair<long long , int>>> minHeap;
        minHeap.push({0 ,src});
        dist[src] = 0;
        while(!minHeap.empty()){
            auto it = minHeap.top();
            minHeap.pop();
            int node = it.second;
            for(auto temp : adjList[node]){
                int adjNode = temp.first;
                long long d = temp.second;
                if(dist[adjNode] == -1 || dist[node] + d < dist[adjNode]){
                    dist[adjNode] = dist[node] + d;
                    minHeap.push({dist[adjNode] , adjNode});
                }
            }
        }
        return dist;
    }
public:
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {
        //Construct the adjacency list for finding out the minimum cost for changing characters
        vector<vector<pair<int , int>>> adjList(26);
        for(int i = 0 ; i < original.size() ; i++){
            adjList[original[i] - 'a'].push_back({changed[i] - 'a' , cost[i]});
        }

        vector<vector<long long>> minConversionCost(26);
        
        //Find the minimum cost for conversion for each character eg : a -> b , a->c and so on
        for(int i = 0 ; i < 26 ; i++){
            minConversionCost[i] = dijkstra(i , adjList);
        }

        int n = source.length();
        long long minimumCost = 0;
        for(int i = 0 ; i < n ; i++){
            if(source[i] != target[i]){
                int minCost = minConversionCost[source[i] - 'a'][target[i] - 'a'];
                if(minCost == -1) return -1;
                minimumCost += minCost;
            }
        }
        return minimumCost;
    }
};