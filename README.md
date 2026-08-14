# my_toy

一个用来享受 game programming 乐趣的玩具项目。

用 C++ 和 [raylib](https://www.raylib.com/) 瞎折腾一些小东西，没有严肃的目标，纯粹是玩。

## Build

依赖通过 CMake `FetchContent` 自动拉取，不需要手动安装 raylib。

```bash
cmake -B build
cmake --build build
```

## Run

```bash
./build/my_toy   # Windows 下为 build/Debug/my_toy.exe
```
