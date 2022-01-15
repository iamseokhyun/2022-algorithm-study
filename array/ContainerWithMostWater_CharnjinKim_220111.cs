public class Solution {
    public int MaxArea(int[] height) {
        int l = 0;
        int r = height.Length-1;
        int max = 0;
        int h;
        while (r>l) {
            h=(height[r]>height[l])?height[l]:height[r];
            max = (max>(h*(r-l)))?max:(h*(r-l));
            if (height[r]>height[l]) {
                l++;
            } else {
                r--;
            }
        }
        return max;
    }
}
