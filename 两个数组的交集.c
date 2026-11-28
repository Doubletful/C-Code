//LeetCode    349.两个数组的交集

//方法一：哈希判断
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int hash[1001] = {0};
    for (int i = 0; i < nums1Size; i++)
    {
        hash[nums1[i]]++;
    }
    int* ans = malloc(sizeof(int) * 1000);
    int idx = 0;
    for (int i = 0; i < nums2Size; i++)
    {
        if (hash[nums2[i]])
            ans[idx++] = nums2[i];
        hash[nums2[i]] = 0;
    }
    *returnSize = idx;
    return ans;
}
