class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2 ;  i <= n ; i++){
            string temp = "";
            int j = 0 , size = ans.size();
            while(j < size){
                int count = 1;
                char ch = ans[j];
                while(j < size && ans[j] == ans[j + 1]){
                    count += 1;
                    j += 1;
                }
                temp += to_string(count) + ch;
                j += 1;
            }
            ans = temp;
        }
        return ans;
    }
};