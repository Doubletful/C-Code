//LeetCode    面试题 10.09.排序矩阵查找

//从右上角遍历(当前行最大，当前列最小)
bool searchMatrix(int** matrix, int matrixSize, int matrixColSize, int target) {
    int i = 0, j = matrixColSize - 1;
    while (i < matrixSize && j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)
            j--;
        else
            i++;
    }
    return false;
}
