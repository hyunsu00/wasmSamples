**빌드 및 실행**  
```
# Emscripten 다운로드 및 설치 후

# 환경변수 스크립트 바로 적용(재부팅없이)
$ source $HOME/emsdk/emsdk_env.sh

# 확인
$ emcc -v

#
# a.out.js, a.out.wasm 생성
#
$ emcc ./hello_world.c
# 테스트
$ node a.out.js
# 빌드파일 지우기
$ rm hello.html hello.js hello.wasm

#
# hello.js, hello.wasm, hello.html 생성
#
$ emcc ./hello_world.c -o hello.html
# js 테스트
$ node hell.js
# html 테스트(liveserver 이용)
# 빌드파일 지우기
$ rm hello.html hello.js hello.wasm

```