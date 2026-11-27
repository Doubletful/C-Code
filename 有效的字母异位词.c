//LeetCode    242.有效的字母异位词

//方法一：哈希表判断
bool isAnagram(char* s, char* t) {
    int hash[26] = {0};
    for (int i = 0; s[i]; i++)
    {
        hash[s[i] - 'a']++;
    }
    for (int i = 0; t[i]; i++)
    {
        hash[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] != 0)
            return false;
    }
    return true;
}
