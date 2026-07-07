class Solution {
public:
    bool isPalindrome(int x) {
        long long copy=x;
        long long rev=0;
        while(copy>0){
            int digit=copy%10;
            rev = rev * 10 + digit;
            copy=copy/10;
        }

        if(x==rev){
            return true;
        }
        return false;

    }
};