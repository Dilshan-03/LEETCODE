class Solution {
private:
    int minFlip(string& s){
        int n = s.length();
        int flipCnt = 0;
        int last = (s[0] - '0' == 0 )? 0 : 1;
        for(int i = 1; i < n ; i++){
            if(last == 0 && s[i] != '1') flipCnt += 1;
            else if(last == 1 && s[i] != '0') flipCnt += 1;
            last = !last;
        }
        int flipFirst = 1;
        last = (s[0] - '0' == 0) ? 1 : 0;
        for(int i = 1; i < n ; i++){
            if(last == 0 && s[i] != '1') flipFirst += 1;
            else if(last == 1 && s[i] != '0') flipFirst += 1;
            last = !last;
        }
        return min(flipCnt , flipFirst);
    }
public:
    int minOperations(string s) {
        string t = s;
        reverse(t.begin() , t.end());
        return min(minFlip(s) , minFlip(t));
    }
};