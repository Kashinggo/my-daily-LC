第一遍过思路，第二遍放实作

# 树和二叉树（共15道）：

4、重建二叉树

17、树的子结构

18、二叉树的镜像

22、从上往下打印二叉树

### 23、二叉搜索树的后序遍历序列
第一次遇到，和重建二叉树一个道理，找到分界，递归左右子树去做

24、二叉树中和为某一值的路径
回溯

### 26、二叉搜索树与双向链表
保存一个pre进行recur

38、二叉树的深度

39、平衡二叉树

### 57、二叉树的下一个结点
存在右孩子（返回右孩子下最左），是双亲的左孩子（返回双亲），都不是（找到第一个在其左孩子下的双亲）。第3种情况最复杂

### 58、对称的二叉树
DFS: recur(left.left, right.right)
BFS: add(root); add(root); add(left.left); add(right.right); add(left.right), ...

59、按之字形顺序打印二叉树

60、把二叉树打印成多行

### 61、序列化二叉树
反序列化较麻烦，具体遍历方式可以是前序、层序（第一次取出来的是最左边的node，本轮的node要重新入队，方便连上接下来的2个孩子）等

62、二叉搜索树的第K个结点


# 链表（共8道题目）：

3、从尾到头打印链表

14、链表中倒数第K个结点

### 15、反转链表
递归（newHead 只是单纯传递最后一个节点，作为新的head，类似于recur(root->left)，传递的是recur(node->next)）和迭代（cur和prev；next是中间变量防丢失）

### 16、合并两个排序的链表

### 25、复杂链表的复制
法2的哈希换时间不难想，重点是法3的 O(1) 的扦插嫁接，隔一个拆成两个链表（1先连3，走到3，2再连3后面的4，走到4）

### 36、两个链表的第一个公共结点
哈希表、双指针、长度差（法3和法2一样，时间是m+n，空间是1）
`while(p1 != p2)`
法2的合理性在于，相遇时2指针的路程都为 a+b+c (c是公共部分长度) 即便 c == 0, 条件也成立 `p1 = p2 = NULL`

55、链表中环的入口结点
速度2的指针一直在环里面打圈，所以相遇点在环内
`(a + b + 2c) = 2(a + c)` 能推导出 起点到环入口 a == 相遇点到环入口 b，环入口到相遇点 c 被抵消了
故以相同的速度1各自从起点和相遇点出发，再次相遇点即是 环入口

### 56、删除链表中重复的结点
```
在 C++ 代码中，存在几个问题：
在删除重复节点的循环中，cur继续遍历直到链表末尾，这是因为删除条件中没有考虑到新的cur->next可能为空，这可能会导致空指针引用。
pre->next = cur;这一行应当在判断结束重复序列后执行，否则可能会错过删除一些重复的节点。
pre的移动逻辑是在循环外的，这意味着如果cur和cur->next值相同，pre将不会正确更新。
```
```java
 if(cur.val!=cur.next.val){
    last=cur;
    cur=cur.next;
 } else {
    int val=cur.val;
    while(cur!=null && cur.val==val) cur=cur.next;
    last.next=cur;
 }
```
# 字符串（共9道题目）：

2、替换空格

### 27、字符串的排列
回溯 DFS，全排列
```py
class Solution:
    res = []
    path = []
    def backtrack(self, ls, visited):
        if len(self.path) == len(ls):
            self.res.append(''.join(self.path))
            return
        for i in range(len(ls)):
            if i > 0 and ls[i] == ls[i - 1] and not visited[i - 1]:
                continue

            if not visited[i]:
                visited[i] = True
                self.path.append(ls[i])
                self.backtrack(ls, visited)
                self.path.pop()
                visited[i] = False

    def permutation(self, s: str) -> List[str]:
        self.res.clear()
        self.path.clear()
        ls = list(s)
        ls.sort()
        visited = [False for _ in range(len(s))]
        self.backtrack(ls, visited)
        return self.res
```

34、第一个只出现一次的字符

43、左旋转字符串

### 44、反转单词序列

### 49、把字符串转换为整数
atoi() yyds

“您一直空腹”

```
“空”：字符串是否为null或者字符串是否为空字符串（过短）
“字”：!!!输入是否合法，判断除首位可能为正负号外，其他位是否都是数字，有无空格等（搞怪）
“负”：字符串对于正负号的处理，特别是正号，可能有也可能没有，但都代表正数（搞鬼）
“溢”：int为32位，最大的整数是刚刚超过21亿，也就是10位十进制数（过长）

“零”：使用错误标志，区分合法值0和非法值0
```
```java
public class Solution {
    public int StrToInt(String str) {
        if(str==null || str.length()<1)
            return 0;
        boolean isVaild=false; //用来标记是否合法
        char c = str.charAt(0);
        int flag=0;
        //通过首位进行判断，并标记
        if(c=='+') //为正数
            flag=1;
        else if(c=='-') //为负数
            flag=-1; // 记得排除 "-0"
        else if(c>='0'&&c<='9') { //正数
            flag=1;
            str="+"+str; //便于统一处理
        }else { //不是数
            isVaild=true;
             return 0;
        }
           
        int len= str.length();
        
        //计算后续数字
        if(len>11) //最大整数是10位
            return 0;
        long res=0;
        for(int i=1;i<len;i++){
            c=str.charAt(i);
            if(c<'0'||c>'9'){
                isVaild=true;
                return 0;
            }
               
            res=res*10+(c-'0'); //计算数值大小
        }
        if(flag==1 && res<=Integer.MAX_VALUE)
            return (int)res;
        if(flag==-1 && (-1*res)>=Integer.MIN_VALUE)
            return (int)(-1*res);
        isVaild=true;
        return 0;
    }        
}
```
### 52、正则表达式匹配

. 和 *

### 53、表示数值的字符串

形如 `A[.[B]][e|EC] 或 .B[e|EC]` 整数小数指数

```java
 public boolean isNumeric(char[] str) {
    //法一：逐位判断
    if(str==null)
        return false;
    boolean sign=false,decimal=false,hasE=false; //标记符号、小数点、指数符号E是否出现过
    for(int i=0;i<str.length;i++){
        if(str[i]=='e'||str[i]=='E'){ // 有e出现
            if(i==str.length-1) // 1. e不能是最后一位，后面必须跟数字
                return false;
            if(hasE) return false; // 2. e只能出现一次
            hasE=true;
        }else if(str[i]=='.'){
            if(hasE||decimal) // 3. 指数不能有小数点  4. 小数点只能出现一次 
                return false;
            decimal=true;
        }else if(str[i]=='+'||str[i]=='-'){
            if((!sign && i!=0 ) && str[i-1]!='e' && str[i-1]!='E') // 5. 第一次出现，只能在开头或e之后
                return false;
            if(sign && str[i-1]!='E' && str[i-1]!='e') // 6. 第二次出现，只能在e之后
                return false;
            sign=true; // 标记出现
        }else if(str[i]>'9'||str[i]<'0') // 7. 出现非法字符
            return false;
    }
    return true;
}
```

54、字符流中第一个不重复的字符


# 数组（共 12 道题目）

1、二维数组中的查找

### 6、旋转数组的最小数字

13、调整数组顺序使奇数位于偶数前面

19、顺时针打印矩阵

28、数组中出现次数超过一半的数字

30、连续子数组的最大和

32、把数组排成最小的数

### 35、数组中的逆序对
按着 merge sort 模版写的，但次数没对上

37、数字在排序数组中出现的次数

40、数组中只出现过一次的数字

### 50、数组中的重复数字
`while(nums[i] != i)` 最多交换2次

### 51、构建乘积数组
1个前缀积数组，搭配1个变量负责后缀累乘

# 非本书但在国区：

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
