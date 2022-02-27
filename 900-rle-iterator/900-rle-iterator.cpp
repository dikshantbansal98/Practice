class RLEIterator {
public:
    int idx = 0;
    vector<int>encodedArray;
    RLEIterator(vector<int>& encoding) {
        encodedArray = encoding;
    }
    
    int next(int n) {
        int last = -1;
        if(idx >= encodedArray.size()) {
            return -1;
        }
        while(n && idx < encodedArray.size() && n >= encodedArray[idx]) {
            n -= encodedArray[idx];
            last = encodedArray[idx+1];
            encodedArray[idx] = 0;
            idx += 2;
        }
        // cout<<idx<<" "<<encodedArray[idx]<<endl;
        
        if(n) {
            if(idx < encodedArray.size()) {
                encodedArray[idx] -= n;
                last = encodedArray[idx+1];
            }
            else{
                last = -1;
            }
        }
        return last;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */