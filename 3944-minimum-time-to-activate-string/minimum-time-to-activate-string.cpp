class Solution {
public:
    bool activate(string temp , int mid , vector<int> &order , int k , int n){
        for(int i = 0 ; i <= mid ; i++){
            temp[order[i]] = '*';
        }
        long long totalinv = 0 , curr = 0;
        for(int i = 0 ; i < n ; i++){
            if(temp[i] == '*'){
                totalinv += ((long long)curr*(curr+1))/2;
                curr = 0;
            }
            else{
                curr++;
            }
        }
        if(temp[n-1] != '*')totalinv += ((long long)curr*(curr+1))/2;
        long long total = ((long long)n*(n+1))/2;
        total -= totalinv;
        cout << "Mid : "<<mid<<" total : "<<total<<" totalinv : "<<totalinv<<endl;
        return (total >= k);
    }
    int minTime(string s, vector<int>& order, int k) {
        int n = s.length();
        int st = 0 , e = n-1;
        int ans = -1;
        string temp = s;
        while(st <= e){
            int mid = st+(e-st)/2;
            if(activate(temp , mid , order , k,n)){
                //cout << "Mid : "<<mid<<endl;
                ans = mid;
                e = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
    }
};