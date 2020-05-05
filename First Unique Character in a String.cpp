class Solution {
public:
    int firstUniqChar(string s) {
        /*unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        for(int i=0;s[i]!='\0';i++)
            if(mp[s[i]]==1)
                return i;
        return -1;*/
        int mp[26]={0};
        for(int i=0; s[i] !='\0'; i++)
            mp[s[i]-'a']++;
        for(int i = 0; s[i] != '\0'; i++)
            if(mp[s[i]-'a']==1)
                return i;
        return -1;
        
    }
};
