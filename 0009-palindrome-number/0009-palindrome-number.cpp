class Solution {
public:
    bool isPalindrome(int x) {
        int n = x;
        long long revNum = 0;

        if(n < 0)
        {
            return false;
        }

        while(x!=0)
        {
            int r = x%10;
            revNum = revNum*10+r;
            x = x/10;
        }
        
        if(revNum == n)
        {
            return true;
        }
        
        return false;
        
    }
};