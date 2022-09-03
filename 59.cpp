/*
    给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
    
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]
*/


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int t = 0;      // top
        int b = n-1;    // bottom
        int l = 0;      // left
        int r = n-1;    // right
        vector<vector<int>> ans(n,vector<int>(n));
        int k=1;
        while(k<=n*n){
            for(int i=l;i<=r;++i,++k) ans[t][i] = k;
            ++t;
            for(int i=t;i<=b;++i,++k) ans[i][r] = k;
            --r;
            for(int i=r;i>=l;--i,++k) ans[b][i] = k;
            --b;
            for(int i=b;i>=t;--i,++k) ans[i][l] = k;
            ++l;
        }
        return ans;
    }
};