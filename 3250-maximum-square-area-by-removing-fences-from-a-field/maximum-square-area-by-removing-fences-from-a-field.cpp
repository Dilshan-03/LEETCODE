class Solution {
private:
    int longestCommonSides(vector<int>& hFences , vector<int>& vFences){
        int n = hFences.size() , m = vFences.size();
        int sideLen = -1;
        unordered_set<int>st;
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n; j++){
                int diff = abs(hFences[j] - hFences[i]);
                st.insert(diff);
            }
        }
        
        for(int i = 0 ; i < m ; i++){
            for(int j = i + 1 ; j < m; j++){
                int diff = abs(vFences[j] - vFences[i]);
                if(st.contains(diff)) sideLen = max(sideLen , diff);
            }
        }
        return sideLen;

    }
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        int side = longestCommonSides(hFences , vFences);
        if(side == -1) return side;
        int area = 1ll * side * side  % 1000000007;
        return area;
    }
};