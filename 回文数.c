//LeetCode    9.回文数

//方法一：折半反转比较
bool isPalindrome(int x) {
    if (x < 0 || x && x % 10 == 0)
        return false;
    long long n = 0;
    while (n < x / 10)
    {
        n = n * 10 + x % 10;
        x /= 10;
    }
    return x == n || x / 10 == n;
}
