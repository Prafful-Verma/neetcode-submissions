class Solution {
public:
    int findTime(vector<int>& piles, int speed) {
        int time = 0;
        cout<<"func--";
        for(int i : piles) {
            int currtime = ceil((double)i/speed);
            cout<<i<<":"<<currtime<<" ";
            time+=currtime;
        }
        cout<<endl;
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (findTime(piles, mid) <= h) {
                hi = mid - 1;      // try smaller speed
            } else {
                lo = mid + 1;  // need larger speed
            }
        }

        return lo;
    }
};
