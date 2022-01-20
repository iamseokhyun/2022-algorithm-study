public class Solution
{
    public bool WordBreak(string s, IList<string> wordDict)
    {
        int[] okUntil = new int[s.Length]; // 어디까지 계산했는지를 저장하기 위한 배열, 0으로 초기화되므로 1이면 true, -1이면 false, 0은 null 의미
        return Solve(s, 0, wordDict, okUntil);
    }
    public bool Solve(string s, int sidx, IList<string> wD, int[] okUntil) //백트래킹 (s, wD는 그대로, sidx와 okUntil이 iteration마다 바뀜)
    {
        if (sidx == s.Length) //sidx가 s의 길이까지 도달했다는 것은 분할에 성공 한 것이므로 true
        {
            return true;
        }
        else if (sidx > s.Length) //같은 이치로 넘어가면 분할에 실패한 것이므로 false.
        {
            return false;
        }
        if (okUntil[sidx] != 0) // 저장된 idx가 null이 아니라면:
        {
            switch (okUntil[sidx])
            {
                case -1:
                    return false; // false라는 것은 backtracking 해야한다는 것 의미
                case 1:
                    return true; // 계속 진행
            }
        }
        bool tf = false; // 한 iteration에서의 tf를 저장하는 bool
        foreach (string word in wD) // Dict 내의 모든 워드에 대해서
        {
            if (isMatch(s, sidx, word)) // s[sidx]이후의 글자가 word와 일치한다면,
            {
                tf = tf || Solve(s, sidx + word.Length, wD, okUntil); // tf = (tf or Solve(sidx+word의 길이))
            }
        }
        if (tf) // 매치되는게 없을때 일로가는데 한번이라도 sidx가 옮겨졌다면 tf가 true이므로
        {
            okUntil[sidx] = 1; // sidx까지는 ok라는 뜻
            return true; //true 출력
        }
        else
        {
            okUntil[sidx] = -1; // sidx까지 배열이 만들어지지 않으므로
            return false; // false 출력
        }
    }
    public bool isMatch(string s, int sidx, string match) // s[sidx..sidx+match.Length] == match 이면 true, 아니면 false 출력하는 메서드
    {
        if (sidx + match.Length <= s.Length)
        {
            if (s[sidx..(sidx + match.Length)].Equals(match))
            {
                return true;
            }
        }
        return false;
    }
}