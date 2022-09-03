/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。
如果不存在符合条件的子数组，返回 0。

示例：

输入：s = 7, nums = [2,3,1,2,4,3] 输出：2 解释：子数组 [4,3] 是该条件下的长度最小的子数组。

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
public:
    int minSubArrayLen(int s, vector<int>& nums) 
    {
        int begin=0;
        int subLength=0;
        int result=INT32_MAX;
        int len=nums.size();
        int sum=0;
        for (int end=0;end<len;++end)
        {
            sum+=nums[end];
            while(sum>=s)
            {
                subLength=end-begin+1;
                result=result<subLength?result:subLength;
                sum-=nums[begin++];
            }
        }
        return result = INT32_MAX ? 0 : result;
    }
};

/*
一些录友会疑惑为什么时间复杂度是O(n)。

不要以为for里放一个while就以为是O(n^2)啊， 主要是看每一个元素被操作的次数，
每个元素在滑动窗后进来操作一次，出去操作一次，每个元素都是被操作两次，所以时间复杂度是 2 × n 也就是O(n)。

*/