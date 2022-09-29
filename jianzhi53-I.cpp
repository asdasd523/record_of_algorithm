/*
统计一个数字在排序数组中出现的次数。

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
*/

//类似于二叉搜索树,进行二分查找


int search(vector<int>& nums, int target) {
        int left = 0,right = nums.size()-1;
        int n = 0;
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                while((mid >= 0) && (nums[mid] == target)){
                    mid--;
                }

                mid++;

                while((mid < nums.size()) && (nums[mid] == target)){
                    mid++;
                    n++;
                }

                break;
            }
        }

        return n;
    }