#include <stdio.h>
#include <string.h>
#include <ctype.h>

void decryptSubstitutionCipher(char *ciphertext, char *key) {
    char mapping[256] = {0};
    int i;
    for ( i = 0; i < 26; i++) {
        mapping[key[i]] = 'A' + i;
    }

    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            printf("%c", mapping[toupper(ciphertext[i])] ? mapping[toupper(ciphertext[i])] : ciphertext[i]);
        } else {
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");
}

int main() {
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83";
    char key[] = {'B', 'U', 'A', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};
    decryptSubstitutionCipher(ciphertext, key);
    return 0;
}

