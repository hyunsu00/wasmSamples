# wasmSamples

## **Emscripten 다운로드 및 설치**
```bash
#
# ubuntu22.04.2 LTS (WSL)
#

# 0. python3, cmake, git 패키지 설치
$ sudo apt update
$ sudo apt install -y python3 cmake git
# 1. 설치위치 - $HOME 
# 2. 최신 SDK 받기
$ git clone https://github.com/emscripten-core/emsdk
$ cd emsdk
# 3. 체크아웃 (main 브렌치)
$ git checkout main
# 4. 최신 SDK 도구를 설치
$ ./emsdk install latest
# 5. 최신 SDK 도구를 활성화
$ ./emsdk activate latest
# 6. 경로 변수 활성화
$ source ./emsdk_env.sh 
# 7. 설치 & 버전 확인
$ emcc --version
# 8. bash 실행시 emsdk 활성화
$ echo 'source "$HOME/emsdk/emsdk_env.sh"' >> $HOME/.bash_profile
```

## **vscode wsl 확장설치**
```bash
# WSL (윈도우에 설치)
https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-wsl

# C/C++ Extension Pack (WSL에 설치)
https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack
```

## **WASM 빌드**
```bash
# 빌드
# -DCMAKE_BUILD_TYPE=Debug
# -DCMAKE_BUILD_TYPE=Release
# -DCMAKE_BUILD_TYPE=MinSizeRel
# -DCMAKE_BUILD_TYPE=RelWithDebInfo
$ mkdir build
$ cd build
$ emcmake cmake -DCMAKE_BUILD_TYPE=Debug ..
$ make -j 8
```

## **참고**
- **emcc options**
```bash
$ emcc --help
"-sOPTION[=VALUE]"
   : Emscripten build options. For the available options, see src/settings.js.

# Emscripten Ports 저장소에서 사용 가능한 프로젝트 목록을 표시
$ emcc --show-ports
   : Check Available ports
   ...
   zlib (USE_ZLIB=1; zlib license)

# 로컬 복사본의 ports 프로젝트 제거
$ emcc --clear-ports

# 캐쉬 지우기
$ emcc --clear-cache
```

- **git CRLF 개행 문자 문제 해결 방법**
```bash
# window CRLF -> LF
$ git config --global core.autocrlf true
# Linux LF만 input으로 설정
$ git config --global core.autocrlf input
```

- **gitignore 대소문자**
```bash
# .gitignore
[Bb]uild/
```