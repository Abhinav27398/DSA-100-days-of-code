//Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.
#include <stdio.h>
#include <string.h>

char nonRepeatingChar(const char* s) {
    int freq[26] = {0};

    // Count frequencies
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Find first non-repeating
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$'; // if all characters repeat
}

int main() {
    char s[] = "geeksforgeeks";
    char ans = nonRepeatingChar(s);

    if (ans != '$')
        printf("First non-repeating character: %c\n", ans);
    else
        printf("All characters repeat, returning: %c\n", ans);

    return 0;
}