

class Solution {
    public:
    bool isPalindrome(int x) {
        int rev = 0, pop
        if (x < 0 | |(x != 0 & & x % 10 == 0))
        return false
        while (x > rev){
            pop = x % 10
            x /= 10
            rev = rev * 10 + pop
        }
        return x == rev | | x == rev / 10
    }
}
