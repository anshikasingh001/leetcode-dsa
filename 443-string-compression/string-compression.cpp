class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        int i = 0;

        while (i < n) {
            char ch = chars[i];
            int count = 0;

            // Count consecutive characters
            while (i < n && chars[i] == ch) {
                i++;
                count++;
            }

            // Write the character
            chars[write++] = ch;

            // Write count if greater than 1
            if (count > 1) {
                string num = to_string(count);

                for (char c : num) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};