char* reverseWords(char* s) {
    int inicio = 0;
    int i = 0;
    
    while (1) {
        if (s[i] == ' ' || s[i] == '\0') {
            int fim = i - 1;
            while (inicio < fim) {
                char temp = s[inicio];
                s[inicio] = s[fim];
                s[fim] = temp;
                inicio++;
                fim--;
            }
            if (s[i] == '\0')
                break;
            inicio = i + 1;
        }
        i++;
    }
    
    return s;
}
