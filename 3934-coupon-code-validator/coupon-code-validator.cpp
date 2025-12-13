class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> electronics , grocery , pharmacy , restaurant;
        int n = code.size();
        vector<string> result;
        for(int i = 0 ; i < n ; i++){
            if(isActive[i]){
                if(businessLine[i] == "restaurant"){
                    int len = code[i].length();
                    int cntLen = 0;
                    for(int k = 0 ; k < len ; k++){
                        if((code[i][k] >= 65 && code[i][k] <= 90) || (code[i][k] >= 97 && code[i][k] <= 122) ||
                            (code[i][k] >= 48 && code[i][k] <= 57) || (code[i][k] == '_'))   
                               cntLen += 1;        
                    }
                    if(cntLen  && cntLen == len) restaurant.push_back(code[i]);
                }
                else if(businessLine[i] == "grocery"){
                    int len = code[i].length();
                    int cntLen = 0;
                    for(int k = 0 ; k < len ; k++){
                        if((code[i][k] >= 65 && code[i][k] <= 90) || (code[i][k] >= 97 && code[i][k] <= 122) ||
                            (code[i][k] >= 48 && code[i][k] <= 57) || (code[i][k] == '_'))   
                               cntLen += 1;        
                    }
                    if(cntLen && cntLen == len) grocery.push_back(code[i]);
                }
                else if(businessLine[i] == "pharmacy"){
                    int len = code[i].length();
                    int cntLen = 0;
                    for(int k = 0 ; k < len ; k++){
                        if((code[i][k] >= 65 && code[i][k] <= 90) || (code[i][k] >= 97 && code[i][k] <= 122) ||
                            (code[i][k] >= 48 && code[i][k] <= 57) || (code[i][k] == '_'))   
                               cntLen += 1;        
                    }
                    if(cntLen && cntLen == len) pharmacy.push_back(code[i]);
                }
                else if(businessLine[i] == "electronics"){
                    int len = code[i].length();
                    int cntLen = 0;
                    for(int k = 0 ; k < len ; k++){
                        if((code[i][k] >= 65 && code[i][k] <= 90) || (code[i][k] >= 97 && code[i][k] <= 122) ||
                            (code[i][k] >= 48 && code[i][k] <= 57) || (code[i][k] == '_'))   
                               cntLen += 1;        
                    }
                    if(cntLen && cntLen == len) electronics.push_back(code[i]);
                }
            }
        }
        if(electronics.size() > 0){
            sort(electronics.begin() , electronics.end());
            for(int i = 0 ; i < electronics.size() ; i++) result.push_back(electronics[i]);
        }
        if(grocery.size() > 0){
            sort(grocery.begin() , grocery.end());
            for(int i = 0 ; i < grocery.size() ; i++) result.push_back(grocery[i]);
        }
        if(pharmacy.size() > 0){
            sort(pharmacy.begin() , pharmacy.end());
            for(int i = 0 ; i < pharmacy.size() ; i++) result.push_back(pharmacy[i]);
        }
        if(restaurant.size() > 0){
            sort(restaurant.begin() , restaurant.end());
            for(int i = 0 ; i < restaurant.size() ; i++) result.push_back(restaurant[i]);
        }
        return result;
    }
};