class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashSet<Character> window = new HashSet<>();

        int left = 0;
        int max = 0;

        for(int right = 0; right<s.length(); right++){
            char c = s.charAt(right);

            while(window.contains(c)){
                window.remove(s.charAt(left));
                left++;
            }

            window.add(c);

            max = Math.max(max, right - left + 1);
        }
        return max;

    }
}