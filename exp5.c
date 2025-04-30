#include <stdio.h>
#include <string.h>
#include <ctype.h>

int modInverse(int a) {
	int i;
    for ( i = 0; i < 26; i++)
        if ((a * i) % 26 == 1) return i;
    return -1;  // No inverse if a not coprime with 26
}

int main() {
    char text[100], result[100];
    int a = 5, b = 8;  // Must ensure gcd(a, 26) = 1
    printf("Enter plaintext: ");
    scanf("%s", text);

    // Encryption
    int i;
    for ( i = 0; text[i]; i++) {
        char c = toupper(text[i]);
        if (isalpha(c))
            result[i] = ((a * (c - 'A') + b) % 26) + 'A';
        else result[i] = c;
    }
    result[strlen(text)] = '\0';
    printf("Encrypted: %s\n", result);

    // Decryption
    int a_inv = modInverse(a);
    for (i = 0; text[i]; i++) {
        char c = result[i];
        if (isalpha(c))
            text[i] = (a_inv * ((c - 'A' - b + 26)) % 26) + 'A';
        else text[i] = c;
    }
    text[strlen(result)] = '\0';
    printf("Decrypted: %s\n", text);
    return 0;
}

