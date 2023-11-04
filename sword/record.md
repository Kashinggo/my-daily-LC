# 数组（共 12 道题目）

【剑指 Offer】1、二维数组中的查找, 2 pointer

【剑指 Offer】6、旋转数组的最小数字

```cpp

```

【剑指 Offer】13、调整数组顺序使奇数位于偶数前面

【剑指 Offer】19、顺时针打印矩阵

【剑指 Offer】28、数组中出现次数超过一半的数字

【剑指 Offer】30、连续子数组的最大和

【剑指 Offer】32、把数组排成最小的数

【剑指 Offer】35、数组中的逆序对

【剑指 Offer】37、数字在排序数组中出现的次数

【剑指 Offer】40、数组中只出现过一次的数字

【剑指 Offer】50、数组中的重复数字

【剑指 Offer】51、构建乘积数组

# 误入：

面试题 01.05.一次编辑, 2 pointer

```cpp
class Solution {
public:
    bool oneEditAway(string a, string b) {
        int m = a.size(), n = b.size();
        if (abs(m - n) > 1) return false;
        if (m < n) return oneEditAway(b, a);
        int i = 0, j = 0, cnt = 0;
        while (i < m && j < n && cnt <= 1) {
            if (a[i] == b[j]) {
                ++i; ++j;
            } else {
                if (m == n) {
                    ++i; ++j;
                } else {
                    ++i;
                }
                ++cnt;
            }
        }
        return cnt <= 1;
    }
};
```
