/*从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。
2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，
可以看成任意数字。A 不能视为 14。*/


/*
输入: [1,2,3,4,5]
输出: True
*/
#include "include.h"

using namespace std;

    bool isStraight(vector<int>& nums) {
        unordered_set<int> repeat;
        int ma = 0, mi = 14;
        for(int num : nums) {
            if(num == 0) continue; // 跳过大小王
            ma = max(ma, num); // 最大牌
            mi = min(mi, num); // 最小牌
            if(repeat.find(num) != repeat.end()) return false; // 若有重复，提前返回 false
            repeat.insert(num); // 添加此牌至 Set
        }
        return ma - mi < 5; // 最大牌 - 最小牌 < 5 则可构成顺子
    }