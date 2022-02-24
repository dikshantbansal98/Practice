/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        while(true) {
            vector<int>value(wordlist.size());
            int maxValue=-1, index=-1;
            for(int i = 0; i < wordlist.size(); ++i) {
                int count = 0;
                for(int j = 0; j < wordlist.size(); ++j) {
                    if(i == j) {
                        continue;
                    }
                    count += matchedChars(wordlist[i],wordlist[j]);
                }
                if(count > maxValue) {
                    maxValue = count;
                    index = i;
                }
            }
            int matches = master.guess(wordlist[index]);
            if(matches == 6) {
                break;
            }
            vector<string>newArr;
            for(int i = 0; i < wordlist.size(); ++i) {
                if(i!=index && matchedChars(wordlist[i],wordlist[index])==matches) {
                    newArr.push_back(wordlist[i]);
                }
            }
            wordlist = newArr;
        }
    }
    
    int matchedChars(string str1, string str2) {
        int count = 0;
        for(int i = 0; i < str1.size(); ++i) {
            count += str1[i]==str2[i];
        }
        return count;
    }
};