/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rainwatertrap.png
上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。
示例:
输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*/
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0||height.size()==1||height.size()==2)//少于三个不能存水
            return false;
        int maxHeight = 0, maxIndex;
        for (int i = 0; i < height.size(); i++) {//遍历整个height数组
            if (height[i] > maxHeight) {
                maxHeight = height[i];//找到最高点的值以及索引
                maxIndex = i;
            }
        }
        
        int sum = 0;
        maxHeight = 0;//最高点置0，水往低处流，从两边开始
        for (int i = 0; i < maxIndex; i++) {//遍历从0到最高点
            if (maxHeight > height[i]) {
                sum += maxHeight - height[i];
            }
            maxHeight = max(maxHeight, height[i]);
        }
        
        maxHeight = 0;
        for (int i = height.size() - 1; i > maxIndex; i--) {//遍历从数组终点到最高点
            if (maxHeight > height[i]) {
                sum += maxHeight - height[i];
            }
            maxHeight = max(maxHeight, height[i]);
        }
        
        return sum;
    }
};