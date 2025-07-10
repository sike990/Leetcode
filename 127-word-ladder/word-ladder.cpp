class Solution {
public:
    bool posnext(string bw , string nex){
        int count = 0;
        int n = bw.length();
        for(int i = 0 ; i < n ;i++){
            if(bw[i] != nex[i] && count == 0){
                count++;
            }
            else if(bw[i] != nex[i] && count != 0){
                return false;
            }
        }

        return (count == 1);
    }
    // void solvedfs(string bw, string &ew, vector<string>& wrd , int n , int &ans , int count , vector<int> &vis){

    //     if(bw == ew){
    //         ans = min(ans , count);
    //         return;
    //     }

    //     if(count >= ans)return;

    //     for(int i = 0 ; i < n ; i++){
    //         if(vis[i] == 0){
    //             if(posnext(bw , wrd[i])){
    //                 vis[i] = 1;
    //                 solvedfs(wrd[i],ew,wrd,n,ans,count+1,vis);
    //                 vis[i] = 0;
    //             }   
    //         }
    //     }
        
    // }
    int solvebfs(string bw , string ew , vector<string> &wrd , int n  , vector<int> &vis){
        queue<pair<string,int>> q;
        q.emplace(bw,1);

        while(!q.empty()){

            auto el = q.front();
            string els = el.first;
            int count = el.second;
            //if(els == ew)return count;
            for(int i = 0 ; i < n ; i++){
                if(vis[i] == 0 && posnext(els , wrd[i])){
                    if(wrd[i] == ew)return count+1;
                    q.emplace(wrd[i],count+1);
                    vis[i] = 1;
                }
            }
            q.pop();
        }

        return 0;
    }
    int ladderLength(string  bw, string ew, vector<string>& wordlist) {

        int n = wordlist.size();
        int ans;
        vector<int> vis(n , 0);
        //solvedfs(bw , ew , wordlist , n , ans , 1 , vis);
        ans = solvebfs(bw , ew , wordlist , n , vis);
        return ans;
    }
};