//列出字符串排列的所有情况
//输入一个字符串，打印出该字符串中字符的所有排列，并不能含重复序列


/*
输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
*/
#include "include.h"

using namespace std;

//递归套循环的代码，最好按照递归的层来分析，即在递归的某一层将其需要作的循环走完，再进入下一层递归分析

class Solution {
public:
    vector<string> permutation(string s) {
        dfs(s, 0);
        return res;
    }
private:
    vector<string> res;
    //搜索
    void dfs(string s,int x){
        if(x == s.size()-1){    //x代表不动的位数
            res.push_back(s);
        }
        unordered_set<int> hash;
        for(int i = x;i < s.size();i++){  //i代表要与x所指的位置换
            if(hash.insert(s[i]).second == false) continue;
            swap(s[x],s[i]);
            dfs(s,x+1);
            swap(s[i],s[x]);
        }
    }
};