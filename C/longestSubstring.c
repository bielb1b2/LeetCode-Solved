#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s);

int main(void) {

    char *test1 = "abcabcbb";
    char *test2 = "bbbbb";
    char *test3 = "pwwkew";
    char *test4 = "  ";
    char *test5 = "a   b";
    char *test6 = " ";
    char *test7 = "dvdf";

    int result1 = lengthOfLongestSubstring(test1);
    int result2 = lengthOfLongestSubstring(test2);
    int result3 = lengthOfLongestSubstring(test3);
    int result4 = lengthOfLongestSubstring(test4);
    int result5 = lengthOfLongestSubstring(test5);
    int result6 = lengthOfLongestSubstring(test6);
    int result7 = lengthOfLongestSubstring(test7);

    printf("%d\n", result1);
    printf("%d\n", result2);
    printf("%d\n", result3);
    printf("%d\n", result4);
    printf("%d\n", result5);
    printf("%d\n", result6);
    printf("%d\n", result7);

    return 0;
}

int findChar(char c, char *array, int arraySize);

int lengthOfLongestSubstring(char* s) {
    int stringLen = strlen(s);
    if (stringLen == 0) return 0;

    int freq[256] = {0};
    int left = 0;
    int right = 0;
    int maxLen = 0;

    while(right < stringLen)
    {
        char c = s[right];

        while(freq[(unsigned char)c] > 0) 
        {
            freq[(unsigned char)s[left]]--;
            left++;
        }

        freq[(unsigned char)c]++;
        int windowSize = right - left + 1;
        if(windowSize > maxLen) {
            maxLen = windowSize;
        }
        
        right++;
    }

    return maxLen;
    
}