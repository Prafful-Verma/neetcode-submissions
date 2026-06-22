class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> autoBahn;
        int n = position.size();
        for (int i = 0; i < n; i++) autoBahn.push_back({position[i], speed[i]});
        sort(autoBahn.rbegin(), autoBahn.rend());
        int fleets = 1;
        double prevTime = (double)(target - autoBahn[0].first) / autoBahn[0].second;
        for (int i = 1; i < n; i++) {
            double currTime = (double)(target - autoBahn[i].first) / autoBahn[i].second;
            if(currTime > prevTime){ fleets++; prevTime = currTime;}
        }
        return fleets;
    }
};
