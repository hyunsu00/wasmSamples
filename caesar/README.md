
## emcc 빌드
```bash
emcc -Os -s STANDALONE_WASM -s EXPORTED_FUNCTIONS="['_caesarEncrypt', '_caesarDecrypt']" -Wl,--no-entry "src/caesar.cpp" -o "public/caesar.wasm"
```