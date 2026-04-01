# C++ Modules (42)

This repository is a collection of 42 C++ projects focused on learning C++ with the C++98 standard and the basics of object-oriented programming.

## Standards and Compilation

- Compiler: `c++`
- Required flags: `-Wall -Wextra -Werror`
- Standard compatibility: `-std=c++98`

## Requirements

To run the exercises, you need:

- A Linux or macOS environment
- A C++ compiler (`c++`, `clang++`, or `g++`)
- `make`

On Ubuntu/Debian, you can install the essentials with:

```bash
sudo apt update
sudo apt install build-essential clang make
```

## Modules

- `cpp00` ([README](./cpp00/README.md))
- `cpp01` ([README](./cpp01/README.md))
- `cpp02` ([README](./cpp02/README.md))
- `cpp03` ([README](./cpp03/README.md))
- `cpp04` ([README](./cpp04/README.md))
- `cpp05` ([README](./cpp05/README.md))
- `cpp06` ([README](./cpp06/README.md))
- `cpp07` ([README](./cpp07/README.md))
- `cpp08` ([README](./cpp08/README.md))
- `cpp09` ([README](./cpp09/README.md))

## Build and Run

Each exercise has its own `Makefile`.

Common available targets:

```bash
make        # build
make re     # rebuild from scratch
make clean  # remove object files
make fclean # remove object files and executable
```

To run an exercise, the usual flow is:

```bash
make
./<executable_name> <args if needed>
```

## Notes

- Each module includes its own `README.md` with exercise overview and run commands.
- Detailed implementation and behavior notes are provided per module/exercise where relevant.

## Environment

- Tested on Linux and macOS
- Compiler toolchain: `c++` / `clang++` / `g++` (C++98 mode)