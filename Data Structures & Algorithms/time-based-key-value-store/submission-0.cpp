class TimeMap {
public:
    map<string,vector<pair<string,int>>> tm;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        tm[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> val = tm[key];
        int n = val.size();
        string value = "";
        if(n==0) return value;
        for(auto i: val){
            if (i.second <= timestamp) value = i.first;
        }
        return value;
    }
};
