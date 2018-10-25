/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true
*/
class Solution {
public:
    bool isValid(string s) {  //bool类型的函数
        int len = s.length();  //string的长度
        vector<char> stack;  //定义一个char类型的vector/栈
        for (int i = 0; i < len; i++) {  //遍历整个string
            // 左括号压栈
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') stack.push_back(s[i]);//当是括号头的时候进行压栈
            else {
                // 右括号出栈
                if (stack.empty()) return false;
                char top = stack[stack.size() - 1];//栈顶
                //注意判断的时候左括号后边一定是右括号
                if (s[i] == ')' && top != '(')
                    return false;
                if (s[i] == ']' && top != '[') 
                    return false;
                if (s[i] == '}' && top != '{') 
                    return false;
                stack.pop_back();
                /*
                向量容器vector的成员函数pop_back()可以删除最后一个元素.并不真正从vertor里面移走数据。
                而函数erase()可以删除由一个iterator指出的元素，也可以删除一个指定范围的元素。
                还可以采用通用算法remove()来删除vector容器中的元素.
                不同的是：采用remove一般情况下不会改变容器的大小，而pop_back()与erase()等成员函数会改变容器的大小。
                */
            }
        }
        // 栈中无多余左括号
        if (stack.size() > 0) return false;
        return true;
    }
};