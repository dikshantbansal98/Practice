class Solution {
public:
    string predictPartyVictory(string senate) {
        int R = 0, D = 0;
        while(1) {
            string res = "";
            bool isR = false, isD = false;
            for(int i = 0; i < senate.size(); ++i) {
                char ch = senate[i];
                if(ch=='R') {
                    isR = true;
                    if(D>0)
                        D--;
                    else
                        R++,res+='R';
                }
                else {
                    isD = true;
                    if(R>0)
                        R--;
                    else
                        D++,res+='D';
                }
                    
            }
            if(!isD)
                return "Radiant";
            if(!isR)
                return "Dire";
            senate = res;
        }
        return "Radiant";
    }
};

