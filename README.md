# wasmSamples

**Emscripten 다운로드 및 설치**  
```
# git clone을 통해 emscripten SDK 다운
$ git clone https://github.com/emscripten-core/emsdk.git

# emsdk 폴더로 이동
$ cd emsdk

# emsdk의 최신 버전을 가져옵니다(처음 복제할 때 필요하지 않음).
$ git pull

# 설치
$ ./emsdk install latest

# 최신 SDK 도구 활성화 (.emscripten 파일 작성)
$ ./emsdk activate latest

# 환경변수 스크립트 바로 적용(재부팅없이)
$ source ./emsdk_env.sh

# 확인
$ emcc -v
```