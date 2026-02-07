class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int deleteCnt = 0;
        stack<char> st;
        for(int i = 0 ; i < n ; i++){
            //Pop the corresponding ba pairs -> b alone 
            if(!st.empty() && st.top() == 'b' && s[i] == 'a'){
                st.pop();
                deleteCnt += 1;
            }
            else st.push(s[i]);
        }
        return deleteCnt;
    }
};