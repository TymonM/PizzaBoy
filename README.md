# PizzaBoy
## Contents
- [Contents](#contents)
- [Overview](#overview)
- [Journal](#journal)
- [Installation and Usage](#installation-and-usage)
  - [MacOS / Linux](#macos--linux)
  - [Windows](#windows)

## Overview
A software for the employees at a pizza restaurant not unlike PizzaHut. My project for the NZQA DTS 91896 assessment, written in C++. This project is focused on TDD ([test driven development](https://en.wikipedia.org/wiki/Test-driven_development)), something I've done before in Rust but never in C++.

See [task.pdf](task.pdf) for the task requirements.

## Journal
While not a formal changelog, my progress is documented in [JOURNAL.md](JOURNAL.md). These are like extended commit messages.

## Installation and Usage
### MacOS / Linux
1. If it isn't already installed, install CMake. This can be done with `brew install cmake` on MacOS, or `sudo apt-get install cmake` on Ubuntu.
2. Clone the repository with `git clone https://github.com/TymonM/PizzaBoy.git`
3. Build it with CMake:
    ```bash
    cd PizzaBoy
    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Release ..
    cmake --build .
    ```
4. While in the `build` directory, run the program with `./PizzaBoy`
5. Or run all tests with `ctest`

### Windows
todo