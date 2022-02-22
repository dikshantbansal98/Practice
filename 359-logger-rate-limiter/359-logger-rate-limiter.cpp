class Logger {
public:
    map<string,int>hash;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(hash.find(message) == hash.end()) {
            hash[message] = timestamp;
            return true;
        }
        if(hash[message] <= timestamp-10) {
            hash[message] = timestamp;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */