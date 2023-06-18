typedef long int i32;
#include <stdint.h>
#include <stdio.h>

// int main()
// {
//   printf("caesar test\n");

//   return 0;
// }

extern "C" {
  void caesarEncrypt(i32 *plaintext, i32 plaintextLength, i32 key) {
    for (int i = 0; i < plaintextLength; i++) {
      plaintext[i] = (plaintext[i] + key) % 26;
    }
  }

  void caesarDecrypt(i32 *ciphertext, i32 ciphertextLength, i32 key) {
    for (int i = 0; i < ciphertextLength; i++) {
      ciphertext[i] = (ciphertext[i] - key) % 26;
    }
  }
}
