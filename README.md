# PizzaBoy
## Contents
- [Contents](#contents)
- [Overview](#overview)
- [Journal](#journal)
- [Testing](#testing)
- [Installation and Usage](#installation-and-usage)
  - [macOS / Linux](#macos--linux)
  - [Windows](#windows)

## Overview
A software for the employees at a pizza restaurant not unlike PizzaHut. My project for the NZQA DTS 91896 assessment, written in C++. This project is focused on TDD ([test driven development](https://en.wikipedia.org/wiki/Test-driven_development)), something I've done before in Rust but never in C++.

See [task.pdf](task.pdf) for the task requirements.

## Journal
While not a formal changelog, my progress is documented in [JOURNAL.md](JOURNAL.md). These are like extended commit messages.

## Testing
This project is thoroughly tested with a lot of unit tests.

All tests can be found in the [tests](tests) directory. Each file is named `test_[FEATURE].cpp` contains one to a few tests, for that particular feature. I use [CTest](https://cmake.org/cmake/help/latest/manual/ctest.1.html) to run these for convenience, but no testing framework is used for writing them, just the custom macros I wrote in [tests/macros.cpp](tests/macros.cpp). While many frameworks do exist, I realised I didn't need a lot of the features they provide, and I wanted to keep things simple, so I made my own.

## Installation and Usage
### macOS / Linux
1. If it isn't already installed, install CMake. This can be done with `brew install cmake` on macOS, or `sudo apt-get install cmake` on Ubuntu.
2. Clone the repository with `git clone https://github.com/TymonM/PizzaBoy.git`
3. Build it with CMake:
    ```bash
    cd PizzaBoy
    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Release ..
    cmake --build .
    ```
4. While in the `build` directory, run the program with `./DTS_91896`
5. Or run all tests with `ctest`

### Windows
todo