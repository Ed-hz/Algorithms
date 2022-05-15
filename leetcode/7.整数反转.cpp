/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long k = 0;
        while(x){
            k = k * 10 + x % 10;
            x /= 10;
            if(((1000000000>=k)&&(k>214748364)&&(x!=0))
                ||((k==214748364)&&(x>7)) 
                ||((-1000000000<=k)&&(k<-214748364)&&(x!=0))
                ||((k==-214748364)&&(x<-8)))
                return 0;
        }
        return k;
    }
};
// @lc code=end

