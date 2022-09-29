    // 利用位操作简化幂运算，快速幂运算的方法
    
    #include "include.h"

    using namespace std;
    double myPow(double x, int n) {
        double res = 1.0f;
        long p = n;

        if(p < 0){
            p = -p;
            x = 1.0f/x;
        }
        //x^n = x^(1b1+2b2+4b3+8b4+....) 
        while(p > 0){
            if((p & 1) == 1){   //当前位为1，可以计算
                res *= x;
            }
            x *= x;   //往后叠加
            p >>= 1;
        }

        return res;
    }