#include<iostream>
#include<vector>
using namespace std;


class solution
{
    //这是闭区间版本
    int er_fen(vector<int>& nums,int target)
    {
        int right=nums.size()-1;
        int left=0;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]<target)
            {
                left=mid+1;
            }
            else if(nums[mid]>target)
            {
                right=mid-1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};