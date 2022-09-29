#include "include.h"
    
/*
给一个栈入序和出序，判断是否对应
*/

/*
pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
true
*/

//结论：一个入栈序列和一个出栈序列可以唯一确定一个方案
using namespace std;
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> stk;   //用一个栈模拟入栈
    int i = 0;

    for(auto num : pushed){
        stk.push(num);

        //1.放入栈中的元素与出栈序列的底部(即栈底)相同，那么直接将该元素取出，表示已验证
        //2.按顺序入栈的元素与出栈序列不同，那么继续入栈,直到碰到与入栈序列的那个元素相同的，再进入栈循环出栈

        while(!stk.empty() && stk.top() == popped[i]){
            stk.pop();
            i++;
        }
    }

    return stk.empty();
}