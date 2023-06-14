#include <stdio.h>
// EMSCRIPTEN_KEEPALIVE 를 사용하기 위해 필요한 헤더
#include <emscripten.h>

// 예약어 추가
EMSCRIPTEN_KEEPALIVE
int add(int num1, int num2) {
    return num1 + num2;
}

int main(int argc, char* argv[]) { 
    printf("hello world\n");
    return 0; 
}

