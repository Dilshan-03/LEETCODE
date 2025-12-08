class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < n ; j++){
                int res = (i * i + j * j);
                if(sqrt(res) == ceil(sqrt(res)) && sqrt(res) <= n)  cnt += 1;
            }
        }
        return cnt;
    }
};