/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <iostream>
#include <cassert>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long i , k = 0;
        while((i = x % 10) || x){
            k = k * 10 + i;
            x /= 10;
            if(((1000000000>=k)&&(k>=746384741)) || ((1000000000<=k)&&(k<=-846384741)))
                return 0;
        }
        return k;
    }
};
// @lc code=end

int main(){
    Solution a;
    cout<<a.reverse(1534236469);
}