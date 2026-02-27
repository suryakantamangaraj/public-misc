public class Solution {
    public int MinOperations(string s) {
        int res1 = 0, res2 = 0;
        for (int i = 0; i < s.Length; i++) {
            if (i % 2 == 0) {
                if (s[i] == '0') {
                    res1++;
                } else {
                    res2++;
                }
            } else {
                if (s[i] == '0') {
                    res2++;
                } else {
                    res1++;
                }
            }
        }
        return Math.Min(res1, res2);
    }
}
