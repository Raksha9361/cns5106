#include <stdio.h>
#include <ctype.h>
int main() {
    char msg[1000];
    int k;
    printf("Enter message: ");
    fgets(msg, sizeof(msg), stdin);
    printf("Enter key (1-25): ");
    scanf("%d", &k);
    int i;

    for ( i = 0; msg[i]; i++) {
        if (isalpha(msg[i])) {
            char base = isupper(msg[i]) ? 'A' : 'a';
            msg[i] = (msg[i] - base + k) % 26 + base;
        }
    }
    printf("Encrypted: %s", msg);
    return 0;
}

