#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 16

// Fake block cipher: XOR with key
void encrypt_block(unsigned char *block, unsigned char *key, unsigned char *output) {
	int i;
    for ( i = 0; i < BLOCK_SIZE; i++) {
        output[i] = block[i] ^ key[i];
    }
}

// CBC-MAC for 1 or 2 blocks
void cbc_mac(unsigned char *key, unsigned char *message, int num_blocks, unsigned char *tag) {
    unsigned char iv[BLOCK_SIZE] = {0};
    unsigned char temp[BLOCK_SIZE];
    int b,i;

    for ( b = 0; b < num_blocks; b++) {
        for ( i = 0; i < BLOCK_SIZE; i++) {
            temp[i] = message[b * BLOCK_SIZE + i] ^ iv[i];
        }
        encrypt_block(temp, key, iv); // cipher block = E_k(M_i ? IV)
    }

    memcpy(tag, iv, BLOCK_SIZE); // Final block is the MAC tag
}

void print_block(const char *label, unsigned char *block) {
    printf("%s: ", label);
    int i;
    for ( i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", block[i]);
    }
    printf("\n");
}

int main() {
    unsigned char key[BLOCK_SIZE] = "SixteenByteKey!";  // 16-byte key
    unsigned char X[BLOCK_SIZE]   = "Attack at dawn!";  // 1-block message
    unsigned char T[BLOCK_SIZE];

    // Step 1: Compute MAC of X
    cbc_mac(key, X, 1, T);
    print_block("MAC(X)", T);

    // Step 2: Create second block: (X ? T)
    unsigned char second_block[BLOCK_SIZE];
    int i;
    for ( i = 0; i < BLOCK_SIZE; i++) {
        second_block[i] = X[i] ^ T[i];
    }

    // Step 3: Create message X || (X ? T)
    unsigned char forged[BLOCK_SIZE * 2];
    memcpy(forged, X, BLOCK_SIZE);
    memcpy(forged + BLOCK_SIZE, second_block, BLOCK_SIZE);

    unsigned char forged_mac[BLOCK_SIZE];
    cbc_mac(key, forged, 2, forged_mac);
    print_block("MAC(X || (X ? T))", forged_mac);

    // Check if they match
    if (memcmp(T, forged_mac, BLOCK_SIZE) == 0) {
        printf("Attack successful: MAC is the same!\n");
    } else {
        printf("Attack failed: MACs differ.\n");
    }

    return 0;
}

