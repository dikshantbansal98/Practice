class FreqStack {
public:
    map<int,stack<int>>stacks;
    set<tuple<int,int,int>>freqSet;
    int operationNumber;
    FreqStack() {
        operationNumber = 0;
    }
    
    void push(int val) {
        operationNumber++;
        int frequency = stacks[val].size();
        if(frequency) {
            int number = stacks[val].top();
            if(freqSet.find({frequency,number,val}) != freqSet.end()) {
                freqSet.erase({frequency,number,val});
            }
        }
        
        stacks[val].push(operationNumber);
        freqSet.insert({frequency+1,operationNumber,val});
    }
    
    int pop() {
        auto [frequency, number, value] = *freqSet.rbegin();
        freqSet.erase(*freqSet.rbegin());
        stacks[value].pop();
        if(frequency > 1 && stacks[value].size()) {
            freqSet.insert({frequency-1,stacks[value].top(),value});
        }
        cout<<value<<endl;
        return value;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */