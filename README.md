rpi-cli-gpio
============

Command line tool for reading / writing to GPIO pins.

## Usage

```sh
gpio --pin <num> [--write]
```

## Compatibility

- Raspberry Pi 1 model B rev 2

## Building

This project uses the cmake build configuration tool. Compiling on the pi is
straightforward.

```sh
# CMake does out of tree builds. Put it in out/Debug
mkdir -p out/Debug
cd out/Debug

# Generate makefiles
cmake -DCMAKE_BUILD_TYPE=Debug ../..

# Build
make
```

There is a CMake toolchain file _rpi.cmake_ provided for cross compiling. It
almost certainly requires changes to function on your machine. Specifically, the
toolchain is likely to reside in location other than `/usr/local/toolchains`.
