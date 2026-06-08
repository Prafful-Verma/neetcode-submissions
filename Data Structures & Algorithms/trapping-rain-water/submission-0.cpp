class Solution {
public:
    void printArr(vector<int>& arr) {
        cout<<"arr - ";
        for (int i : arr) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    int trap(vector<int>& height) {
        int n = height.size(),m=0,water=0;
        vector<int> l(n);
        vector<int> r(n);
        for(int i=0;i<n;i++){
            m = max(m,height[i]);
            l[i] = m;
        }
        m=0;
        for(int i=n-1;i>=0;i--){
            m = max(m,height[i]);
            r[i] = m;
        }
        for(int i=1;i<n-1;i++){
            int w = min(l[i],r[i])-height[i];
            water+=w;
        }
        return water;
    }
};
