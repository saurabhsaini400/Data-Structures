class TimeMap {
public:
    
    unordered_map<string , map<int , string>> mapping;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mapping[key][-timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        return mapping[key].lower_bound(-timestamp) -> second;
    }
};