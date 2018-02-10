/*
题目描述
给出一个二维数组, 判断其是否为托普利兹矩阵.
1234
5123
9512

思路
二维数组为 matrix[m][n], 用一个额外的一维数组 temp(n) 存储当前比较的数组.

temp 的初值为 matrix 的最后一行.
删除 temp 的第一个元素, 之后在 temp 的最后添加上一行的最后一个元素. 此时如果是托普利兹矩阵的话, temp 应与上一行完全一致. 如果有任何一个不一致, 返回 false.
重复 2. 直到第一行. 返回 true.
复杂度 O(mn).
*/
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> temp;
    for(int i = 0; i < n; i++){
        temp.push_back(matrix[m-1][i]);
    }
    for(int i = m - 2; i >= 0; i--){
        temp.erase(temp.begin());
        temp.push_back(matrix[i][n-1]);
        for(int j = 0; j < n - 1; j++){
            if(matrix[i][j] != temp[j])
                return false;
        }
    }
    return true;
}
