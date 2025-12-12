class Solution {
private:
    bool static comp(vector<string>& a , vector<string>& b){
        int id1 = stoi(a[1]) , id2 = stoi(b[1]);
        //If Timer is same , sort by Message String , Offline events has more priority
        if(id1 == id2){
            return (a[0][0] > b[0][0]);
        }
        return (id1 < id2);
    }
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> count(numberOfUsers , 0) , awakeTimer(numberOfUsers , 0);
        sort(events.begin() , events.end() , comp);
        for(auto it : events){
            string e = it[0];
            int timestamp = stoi(it[1]);
            string mstr = it[2];
            //O Stands For OFFLINE
            if(e[0] == 'O'){
                int id = stoi(mstr);
                awakeTimer[id] = timestamp + 60;
            }
            else{
                //A stands for ALL
                if(mstr[0] == 'A'){
                    for(int i = 0 ; i < numberOfUsers ; i++) count[i] += 1;
                }
                //H stands for HERE
                else if(mstr[0] == 'H'){
                    for(int i = 0 ; i < numberOfUsers ; i++){
                        if(awakeTimer[i] <= timestamp) count[i] += 1;
                    }
                }
                else{
                    stringstream ss(mstr);
                    string idStr;
                    while(ss >> idStr){
                        int id = stoi(idStr.substr(2));
                        count[id] += 1;
                    }
                }
            }
        }
        return count;

    }
};