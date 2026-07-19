class Solution {
public:
    int reverse(int x) {
        int revNum = 0;
        while(x!=0)
        {
            if(revNum > INT_MAX/10 || revNum == INT_MAX && x%10 > 7)
            {
                return 0;
            }
            if(revNum < INT_MIN/10 || revNum == INT_MIN && x%10 < -8)
            {
                return 0;
            }
            revNum = revNum*10 + x%10;
            x=x/10;    
        }
        return revNum;
    }
};