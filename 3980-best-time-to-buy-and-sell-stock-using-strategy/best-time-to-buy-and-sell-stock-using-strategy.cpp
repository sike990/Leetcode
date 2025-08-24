class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> ps(n,0);
        vector<long long> ss(n,0);
        ps[0] = prices[0];
        ss[0] = prices[0]*strategy[0];
        for(int i = 1 ; i < n ; i++){
            ps[i] = ps[i-1]+prices[i];
            long long el = ss[i-1]+long(prices[i]*strategy[i]);
            ss[i] = el;
        }
        long long ssumel = ss[n-1];
        long long ans = ssumel;
        for(int i = 0 ; i <= n-k ; i++){
            long long pv = ps[i+k-1]-ps[i+(k/2)-1];
            long long back = (i == 0)?0:ss[i-1];
            long long sv = ss[i+k-1]-back;

            long long buffer = pv-sv;

            ans = max(ans , buffer+ssumel);
        }

        return ans;

    }
};