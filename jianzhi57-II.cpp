#include "include.h"
    
/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
*/

/*
示例:
输入：target = 9
输出：[[2,3,4],[4,5]]
*/
using namespace std;
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        deque<int> m_que;
        int sum = 0,i=1;
        while(i <= target){
            
            if(sum < target){
                m_que.push_back(i);
                sum += i;
                i++;
            }

            if(sum == target){
                if(m_que.size() == 1) return res;
                vector<int> array;
                for(auto itr = m_que.begin();itr < m_que.end();itr++){
                    array.push_back(*itr);
                }
                res.push_back(array);
                sum -= m_que.front();
                m_que.pop_front();
            }

            if(sum > target){
                while(sum > target){
                        sum -= m_que.front();
                        m_que.pop_front();
                }
            }
        }

        return res;
    }