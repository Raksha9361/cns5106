#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char msg[1000], key[27];
    printf("Enter message: ");
    fgets(msg, sizeof(msg), stdin);
    printf("Enter 26-letter key (A-Z): ");
    scanf("%s", key);
    int i;

    for ( i = 0; msg[i]; i++) {
        if (isupper(msg[i]))
            msg[i] = key[msg[i] - 'A'];
        else if (islower(msg[i]))
            msg[i] = tolower(key[msg[i] - 'a']);
    }

    printf("Encrypted: %s", msg);
    return 0;
}

