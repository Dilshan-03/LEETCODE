class Solution {
private:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    bool doesAliceWin(string s) {
        int n = s.length();
        int cntVowels = 0;
        for(int i = 0 ; i < n ; i++){
            if(isVowel(s[i])) cntVowels += 1;
        }
        bool turn = true; //Alice -> true , Bob -> False
        while(cntVowels){
            if(turn){
                if(cntVowels % 2 == 1) return true;
                else cntVowels -= 1;
            }
            else{
                if(cntVowels % 2 == 0) return false;
            }
            turn = !turn;
        }
        return false;
    }
};