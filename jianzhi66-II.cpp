#include "include.h"


//构建乘积数组
//给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
//其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 
//即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

/*
输入: [1,2,3,4,5]
输出: [120,60,40,30,24]
*/


//解法:列出表格，用计算上三角和下三角的数积

/*
1
a[0] 1
.       1
.          1
.               a[n-1]
.                1
*/

using namespace std;



vector<int> constructArr(vector<int>& a) {

        int n = a.size();
        vector<int> res(n,1);


        //上三角
        int num = 1;
        for(auto i = 1;i < n;i++){
            num *= a[i-1];
            res[i] *= num;
        }


        //下三角
        num = 1;
         for(auto i = n-1;i > 0;i--){
             num *= a[i];
             res[i-1] *= num; 
         }

        return res;
    }