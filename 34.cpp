#include<iostream>
#include<vector>
using namespace std;


/*

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：你可以设计并实现时间复杂度为 $O(\log n)$ 的算法解决此问题吗？

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]

*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int leftBorder=getLeftBorder(nums,target);
        int rightBorder=getRigthBorder(nums,target);

        if(leftBorder==-2 || rightBorder==-2)
        {
            //这是target范围在数组之外的，即target<nums[0]
            //或者target>nums[size-1]
            return {-1,-1};
        }
        if (rightBorder - leftBorder > 1) 
        {
            return {leftBorder + 1, rightBorder - 1};
        }

        return {-1,-1};
        //如果以上情况都不符合，
        //说明target<nums[size-1],target>nums[0],但是target不在nums里面出现过，所以此时按照二分的条件，左边界一定大于右边界且都不会为-2
    }

    int getRigthBorder(vector<int>& nums,int target)
    {
        int left=0;
        int rightBorder=-2;
        //这里是因为这个右边界是不包含target的，也就是开区间，如果写-1的话就说明0处就是target，是不对的
        int right=nums.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]>target)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
                rightBorder=left;
                //以上可以想象为在接近右边界的途中，如果需要靠近右边界，
                //则应该使得left靠近右边界
                //上面两句话先后顺序没关系

            }
        }
        return rightBorder;
    }

    int getLeftBorder(vector<int>& nums,int target)
    {
        int left=0;
        int right=nums.size()-1;
        int leftBorder=-2;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]<target)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
                leftBorder=right;

            }
        }
        return leftBorder;
    }
};