#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toUpperCase(char *s) {
	int i;
    for ( i = 0; s[i]; i++)
        if (isalpha(s[i])) s[i] = toupper(s[i]);
}

void encrypt(char *pt, char *key, char *ct) {
    int n = strlen(pt), klen = strlen(key);
    int i;
    for ( i = 0; i < n; i++)
        ct[i] = ((pt[i] - 'A') + (key[i % klen] - 'A')) % 26 + 'A';
    ct[n] = '\0';
}

void decrypt(char *ct, char *key, char *pt) {
	int i;
    int n = strlen(ct), klen = strlen(key);
    for ( i = 0; i < n; i++)
        pt[i] = ((ct[i] - 'A') - (key[i % klen] - 'A') + 26) % 26 + 'A';
    pt[n] = '\0';
}

int main() {
    char pt[100], key[100], ct[100], dpt[100];
    printf("Plaintext: "); scanf("%s", pt);
    printf("Key: "); scanf("%s", key);

    toUpperCase(pt); toUpperCase(key);

    encrypt(pt, key, ct);
    printf("Encrypted: %s\n", ct);

    decrypt(ct, key, dpt);
    printf("Decrypted: %s\n", dpt);
    return 0;
}

