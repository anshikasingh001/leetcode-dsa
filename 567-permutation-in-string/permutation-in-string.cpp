class Solution {
public:

    bool isFreqSame(int freq1[], int freq2[]) {
        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {

        int freq[26] = {0};

        // Frequency of s1
        for(char ch : s1) {
            freq[ch - 'a']++;
        }

        int windSize = s1.length();
        int windFreq[26] = {0};

        // First window
        for(int i = 0; i < windSize && i < s2.length(); i++) {
            windFreq[s2[i] - 'a']++;
        }

        if(isFreqSame(freq, windFreq)) {
            return true;
        }

        // Sliding window
        for(int i = windSize; i < s2.length(); i++) {

            // Add new character
            windFreq[s2[i] - 'a']++;

            // Remove old character
            windFreq[s2[i - windSize] - 'a']--;

            if(isFreqSame(freq, windFreq)) {
                return true;
            }
        }

        return false;
    }
};