class Solution {
public:
    int binaryGap(int n) {
        string binary = "";
        while(n > 0){
            char rem = (n % 2) + '0';
            binary.push_back(rem);
            n = n / 2;
        }
        reverse(binary.begin() , binary.end());
        int len = binary.size();
        int lastPos = -1;
        int maxDist = 0;
        for(int i = len - 1 ; i >= 0 ; i--){
            if(binary[i] == '1'){
                if(lastPos != -1) maxDist = max(maxDist , len - 1 - i - lastPos);
                lastPos = len - 1 - i;
            }
        }
        return maxDist;
    }
};