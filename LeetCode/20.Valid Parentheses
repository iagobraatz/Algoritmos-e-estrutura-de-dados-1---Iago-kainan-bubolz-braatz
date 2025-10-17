#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    if (len % 2 != 0) return false;
    
    char stack[len];
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        char current = s[i];
        
        if (current == '(' || current == '[' || current == '{') {
            stack[++top] = current;
        }
        else {
            if (top == -1) return false;
            
            char topChar = stack[top--];
            
            if ((current == ')' && topChar != '(') ||
                (current == ']' && topChar != '[') ||
                (current == '}' && topChar != '{')) {
                return false;
            }
        }
    }
    
    return top == -1;
}

int main() {
    // Test cases
    char* test_cases[] = {
        "()",        // true
        "()[]{}",    // true
        "(]",        // false
        "([])",      // true
        "([)]",      // false
        "{[]}",      // true
        "]",         // false
        "(",         // false
        "",          // true
        "((()))",    // true
        "((())",     // false
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < num_tests; i++) {
        bool result = isValid(test_cases[i]);
        printf("isValid(\"%s\") = %s\n", test_cases[i], result ? "true" : "false");
    }
    
    return 0;
}
