class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map <int,int> mp1,mp2;
        if(N == 1)
            return 1;
        for(int i = 0; i < trust.size(); ++i){
            mp1[trust[i][1]]++;
            mp2[trust[i][0]] = 1;
        }
        for(auto i : mp1){
            if(i.second == N-1 && !mp2[i.first])
                return i.first;
        }
        return -1;
        
        
    }
};
