#include "include.h"

using namespace std;

/*输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return {};
        int row = matrix.size(),column = matrix[0].size();
        int i = 0,j = 0;
        const vector<vector<int>> state = { vector<int>({0,1}),
                                            vector<int>({1,0}),
                                            vector<int>({0,-1}),
                                            vector<int>({-1,0})}; 

        vector<int> res;
        int indicate = 0;

        //O(n)
        for(long num = 0;num < (row*column);num++){
            res.push_back(matrix[i][j]);
            matrix[i][j] = INT_MAX;

            i += state[indicate][0];
            j += state[indicate][1];

            //测试是否碰壁
            if(i < 0 || i > row-1 || j < 0 || j > column-1 || matrix[i][j] == INT_MAX){

                if(i < 0 || i > row-1){
                    if(i < 0) i++;
                    else if(i > row-1) i--;

                }else if(j < 0 || j > column-1){
                    if(j < 0) j++;
                    else if(j > column-1) j--;

                }else if(matrix[i][j] == INT_MAX){
                    if(state[indicate][0] != 0){
                        i -= state[indicate][0];
                    }
                    else if(state[indicate][1] != 0){
                        j -= state[indicate][1];
                    }
                }

                if(++indicate == 4) indicate = 0;  //转向

                i += state[indicate][0];   //转向后前进一格
                j += state[indicate][1];
            }
        }

        return res;
    }
};