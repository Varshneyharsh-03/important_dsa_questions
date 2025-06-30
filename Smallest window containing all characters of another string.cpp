string minWindow(string s, string t) {
    if (s.length() < t.length()) return "";

    unordered_map<char, int> freqT;
    for (char c : t) freqT[c]++;

    int left = 0, right = 0, minLen = INT_MAX, start = 0;
    int count = t.length();

    while (right < s.length()) {
        if (freqT[s[right]] > 0) count--;

        freqT[s[right]]--; // Decrease char count whether it's in t or not
        right++;

        while (count == 0) {
            if (right - left < minLen) {
                minLen = right - left;
                start = left;
            }

            freqT[s[left]]++;
            if (freqT[s[left]] > 0) count++; // We need this character again
            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}
