class Solution {
private:
    string helper(string s){
        string temp = "";
        int j = 0 , size = s.size();
        while(j < size){
            int count = 1;
            char ch = s[j];
            while(j < size && s[j] == s[j + 1]){
                count += 1;
                j += 1;
            }
            temp += to_string(count) + ch;
            j += 1;
        }
        return temp;
    } 
public:
    string countAndSay(int n) {
        string ans = "1";
        //Just simulate , what's given there iteratively!!!
        for(int i = 2 ;  i <= n ; i++){
            ans = helper(ans);
        }
        return ans;
    }
};