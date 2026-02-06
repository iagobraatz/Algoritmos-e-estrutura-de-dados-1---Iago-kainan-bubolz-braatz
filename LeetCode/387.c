#include <string.h>

int firstUniqChar(char* s) {
    int frequencia[26] = {0};
    int tamanho = strlen(s);
    
    for (int i = 0; i < tamanho; i++)
        frequencia[s[i] - 'a']++;
    
    for (int i = 0; i < tamanho; i++)
        if (frequencia[s[i] - 'a'] == 1)
            return i;
    
    return -1;
}
