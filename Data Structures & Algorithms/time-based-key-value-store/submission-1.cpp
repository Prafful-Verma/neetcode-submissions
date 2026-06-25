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
        int lo = 0, hi = n-1;
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if (val[mid].second > timestamp) {
                hi = mid-1;
            }else {
                lo = mid+1;
                value = val[mid].first;
            }
        }
        return value;
    }
};
