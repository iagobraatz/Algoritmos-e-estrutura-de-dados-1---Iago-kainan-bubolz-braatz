int strStr(char* haystack, char* needle) {
    if (!needle[0]) return 0;

    for (int i = 0; haystack[i]; i++) {
        int j = 0;
        while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j])
            j++;
        if (!needle[j])
            return i;
    }

    return -1;
}
