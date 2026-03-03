class Solution {
private:
    string flipReverse(string& temp){
        int n = temp.length();
        string result = "";
        for(int i = n - 1 ; i >= 0 ; i--){
            if(temp[i] == '1') result.push_back('0');
            else result.push_back('1');
        }
        return result;
    }
public:
    char findKthBit(int n, int k) {
        string prev = "0";
        string cur = "";
        for(int i = 1 ; i < n ; i++){
            cur = prev + "1" + flipReverse(prev);
            prev = cur;
        }
        return prev[k - 1];
    }
};