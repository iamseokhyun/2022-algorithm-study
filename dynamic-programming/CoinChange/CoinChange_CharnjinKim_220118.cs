// coins = [1, 2, 5] amount=11인 예시에서,
// 11원을 만들기 위한 최소갯수 = (10,9,6)원을 만들기 위한 최소갯수 중 최솟값 +1
// 10원에 대해, 9원에 대해, 6원에 대해 같은 것 반복 -> 1원부터 올라가며 최소갯수 array 저장
using System.Collections.Generic;
public class Solution
{
    public int CoinChange(int[] coins, int amount)
    {

        int[] minval = new int[amount + 1];
        //minval : index원의 돈을 만들기 위해 들어가는 최소 동전갯수, 만들수없다면 -1
        for (int i = 1; i < amount + 1; i++)
        {
            minval[i] = -1; //일단 -1로 초기화
        }
        foreach (int item in coins)
        {
            if (item<=amount)
            {
                minval[item] = 1; // i원을 만들어야하는데 i원짜리 동전이 있다면 1번만에 가능.
            }
        }
        for (int i = 2; i < amount + 1; i++) 
        // i=2원부터 amount 원까지 쭉 서칭을 함.
        // i원을 만들기 위한 최소 갯수 = (i-coins[] 원 만들기 위한 최소갯수) 중에서 최솟값 + 1
        {
            List<int> ar2 = new List<int>(); // i-coins[]가 0보다 커야 후보에 들어가므로 가능한 후보만 넣는 리스트
            for (int j = 0; j < coins.Length; j++)
            {
                if (i - coins[j] > 0)
                {
                    ar2.Add(coins[j]);
                }
            }
            int minvalue = int.MaxValue;
            int minidx = -1; //만든것중 최솟값 저장. minidx는 지금보니 필요없지만 최솟값일때의 넣은 코인의 단위 표시
            for (int j = 0; j < ar2.Count; j++)
            {
                if (minval[i - ar2[j]] != -1 && minval[i - ar2[j]] + 1 < minvalue)
                {
                    minvalue = minval[i - ar2[j]] + 1;
                    minidx = ar2[j];
                } //가능한 코인들 중 계산했을 떄 최솟값인 애를 갱신
            }
            if (minvalue > minval[i] && minval[i] != -1) //5원을 만들어야 하는데 2+2+1보다 5가 횟수가 적을 수도 있으므로
            {
                continue;
            }
            else if (minidx == -1) //후보를 살펴봤지만 만들 수 없는 경우 -1을 그대로 반환
            {
                minval[i] = -1;
            }
            else //minvalue 반환
            {
                minval[i] = minvalue;
            }
        }
        return minval[amount]; 
    }
}