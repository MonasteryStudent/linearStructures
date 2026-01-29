# Introduction

A small project to refresh my C++ skills and explore linear data structures.

## Build
```
cmake -S . -B build
cmake --build build
```

## Rebuilding
```
cmake --build build --clean-first
```

## Run tests with CTest
```
ctest --test-dir build
```

## Notes
- Uses CMake
- Tests use cassert and CTest