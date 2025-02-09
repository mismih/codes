#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TABLE_SIZE 256


void count_chars(char* str, int* count) {
    for (int i = 0; str[i] != '\0'; i++) {
        count[(int)str[i]]++; 
    }
}


int is_anagram(char* s, char* t) {
   
    if (strlen(s) != strlen(t)) {
        return 0;  
    }

    
    int count_s[TABLE_SIZE] = {0};  
    int count_t[TABLE_SIZE] = {0};  

    
    count_chars(s, count_s);
    count_chars(t, count_t);

    
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (count_s[i] != count_t[i]) {
            return 0;  
        }
    }

    return 1;  
}

int main() {
    char s[] = "hashmap";
    char t[] = "mashhap";

    if (is_anagram(s, t)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
