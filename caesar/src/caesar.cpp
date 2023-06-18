// caesar.cpp
#include <stdint.h> // int32_t
#include <stdio.h> // printf
#include <string> // std::string

int main()
{
  std::string str1 = "1234";
	str1 += "5678";
  printf("%s\n", str1.c_str());
  printf("caesar test\n");
  return 0;
}

extern "C" {
  void caesarEncrypt(int32_t* plaintext, int32_t plaintextLength, int32_t key) {
    std::string str1 = "1234";
	  str1 += "5678";
    printf("%s\n", str1.c_str());
    for (int i = 0; i < plaintextLength; i++) {
      plaintext[i] = (plaintext[i] + key) % 26;
    }
  }

  void caesarDecrypt(int32_t* ciphertext, int32_t ciphertextLength, int32_t key) {
    for (int i = 0; i < ciphertextLength; i++) {
      ciphertext[i] = (ciphertext[i] - key) % 26;
    }
  }
}
