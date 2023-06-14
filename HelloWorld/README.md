# Linux: Compile C++ to WebAssembly and JavaScript using Emscripten and CMake #

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

**프로젝트 구조**  
```
build/  
include/  
src/  
public/  
CMakeLists.txt  
```
* build 디렉토리는 빈 상태로 시작하고 헤더(.h) 파일을 /include 안에, 소스(.cpp) 파일을 /src 안에 넣습니다. 

* public 디렉토리는 출력 파일이 저장되는 곳이며 index.html, 이미지 및 css도 여기에 보관합니다.

* CMakeLists.txt는 루트 디렉토리를 유지합니다. 

* 루트 디렉토리에서 다음을 실행하여 CMAKE 도구 체인 파일을 설정하십시오.: `CMAKE_TOOLCHAIN_FILE=/home/user/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake` 
emsdk 설치 위치로 경로를 업데이트됐는지 확인하십시오.

**WASM으로 컴파일 (default)**  
```
cd build  
emcmake cmake ..  
make
```

**JS로 컴파일**  
```
cd build  
emcmake cmake .. -DJS_ONLY=ON  
make
```

**파일 편집 후**  
```
make
```

**파일 추가/제거 후**  
```
emcmake cmake ..  
make
```

**emsdk 디렉토리가 이동된 경우**  
* 프로젝트 루트 디렉토리에서 실행: `CMAKE_TOOLCHAIN_FILE=[/path/to]/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake`  
* 그런 다음 /build 디렉토리에서 다음을 실행합니다.: `emcmake cmake ..`

* 출력 .js, .wasm.js 및 wasm.wasm 파일이 public 디렉토리에 나타납니다.
* 웹 서버가 /public에서 제공되는지 확인하십시오.
* WebAssembly가 클라이언트 브라우저에서 지원되지 않는 경우 index.html은 a.js를 로드합니다.

오류가 발생하면: `fatal error: emscripten.h: No such file or directory` or `The program 'emcmake' is currently not installed` or `The program 'emconfigure' is currently not installed` 이 표시되면 CMAKE_TOOLCHAIN_FILE 경로가 올바른지 확인하십시오. 이것이 종종 원인입니다. /build 디렉토리를 제거하여 재설치를 시도하고 emscripten 설치를 다시 실행하여 마지막에 `source ./emsdk_env.sh`를 실행해야 합니다. 그런 다음 /build 디렉토리를 다시 생성하고 `emcmake cmake ..` 및 `make`를 다시 실행합니다.