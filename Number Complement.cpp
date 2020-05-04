class Solution {
public:
    int findComplement(int num) {
        // Let n be no of bits in nums
        // Let x be a no of n bits with all bits set i.e. 1
        // (num xor x) will give the complement of num
        int i = 1;
        while(i < num){
            i = (i << 1) + 1;
            
        }
        return num ^ i;
        
        
        
    }
};
