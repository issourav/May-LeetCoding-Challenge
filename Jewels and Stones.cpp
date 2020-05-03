class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char,int> mp;
        int ans = 0;
        for(int i = 0; J[i]!='\0';i++)
            mp[J[i]] = 1;
        for(int i = 0; S[i]!='\0';i++)
            if(mp[S[i]])
                ans++;
        return ans;
        
    }
};
