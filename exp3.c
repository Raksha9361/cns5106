#include <stdio.h>
#include <ctype.h>
char m[5][5];
void build(char *k) {
    int used[26] = {0}, i, j, x = 0;
    used['J'-'A'] = 1;
    for (i = 0; k[i]; i++) {
        char c = toupper(k[i]);
        if (isalpha(c) && !used[c-'A']) m[x/5][x%5] = c, used[c-'A'] = 1, x++;
    }
    char c;
    for ( c = 'A'; c <= 'Z'; c++)
        if (!used[c-'A']) m[x/5][x%5] = c, x++;
}
void pos(char c, int *r, int *c_) {
    if (c == 'J') c = 'I';
    int i,j;
    for ( i = 0; i < 5; i++)
        for ( j = 0; j < 5; j++)
            if (m[i][j] == c) *r = i, *c_ = j;
}

void enc(char *t) {
	int i;
    for (i = 0; t[i]; i += 2) {
        char a = toupper(t[i]), b = toupper(t[i+1] ? t[i+1] : 'X');
        if (a == b) b = 'X';
        int r1, c1, r2, c2;
        pos(a, &r1, &c1); pos(b, &r2, &c2);
        if (r1 == r2) printf("%c%c", m[r1][(c1+1)%5], m[r2][(c2+1)%5]);
        else if (c1 == c2) printf("%c%c", m[(r1+1)%5][c1], m[(r2+1)%5][c2]);
        else printf("%c%c", m[r1][c2], m[r2][c1]);
    }
}
int main() {
    char k[100], t[100];
    printf("Key: "); scanf("%s", k);
    printf("Text: "); scanf("%s", t);
    build(k);
    printf("Encrypted: "); enc(t);
    return 0;
}

