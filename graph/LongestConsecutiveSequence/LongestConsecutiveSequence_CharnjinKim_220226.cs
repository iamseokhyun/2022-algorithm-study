using System.Collections.Generic;
public class Solution {
    public int LongestConsecutive(int[] nums) {
        if (nums.Length==0) {
            return 0;
        }
        Dictionary<int, int> save = new Dictionary<int,int>();
        foreach (int number in nums) {
            if (!save.ContainsKey(number)) {
                save.Add(number, 1);
            }
        }
        int stack = 0;
        int cur = -1;
        int max = 1;
        foreach (int number in save.Keys) {
            if (save.ContainsKey(number+1)) {
                if (save[number+1]==1) {
                    stack = 2;
                    cur = number;
                    while (save.ContainsKey(cur+stack)) {
                        if (save[cur+stack]!=1) {
                            stack +=save[cur+stack];
                            save[number] = stack;
                            break;
                        }
                        stack++;
                    }
                    max = (stack>max) ? stack : max;
                    save[number]=stack;
                } else {
                    stack = save[number+1] +1;
                    save[number]=stack;
                    max = (stack>max)? stack : max;
                }

            }
        }
        var stacks = new List<int>(save.Values);
        foreach (int num in stacks) {
            max = (num>max) ? num : max;
        }
        return max;
    }
}