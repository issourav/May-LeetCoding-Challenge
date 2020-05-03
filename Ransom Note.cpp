class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26] = {0};
        for(char c: ransomNote)
            arr[int(c-'a')]++;
        for(char c: magazine)
            arr[int(c-'a')]--;
        for(int i = 0; i < 26; i++)
            if(arr[i] > 0)
                return false;
     
        return true;

        
    }
};
