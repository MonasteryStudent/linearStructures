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

## Build & Test with Makefile

You can also use the included `Makefile` to simplify common tasks:

- Configure & build:
```
make build
```

- Run tests:
```
make test
```

- Clean the build folder:
```
make clean
```

- Only configures CMake without building:
```
make configure
```