#include <stdio.h>

int modInv(int a) {
	int i;
    for ( i = 1; i < 26; i++) if ((a * i) % 26 == 1) return i;
    return -1;
}

int main() {
    char ct[100] = "Ball";  // Example ciphertext
    int x1 = 'E' - 'A', x2 = 'T' - 'A'; // guessed plaintext
    int y1 = 'B' - 'A', y2 = 'U' - 'A'; // ciphertext

    int a = ((x1 - x2) * modInv((y1 - y2 + 26) % 26)) % 26;
    int b = (x1 - a * y1 + 26 * 26) % 26;
    int a_inv = modInv(a);
    int i;

    for ( i = 0; ct[i]; i++)
        ct[i] = (a_inv * ((ct[i] - 'A' - b + 26)) % 26) + 'A';

    printf("Decrypted: %s\n", ct);
    return 0;
}

