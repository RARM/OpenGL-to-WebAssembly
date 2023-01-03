# 01 Introduction
## Setup the Environment

**Goal**: The objective of this section is to setup an environment for later development.

This tutorial uses gcc/g++ on Ubuntu throughout the tutorial. The gcc compiler was installed while preparing a virtual machine using the following command:

```console
rodolfo@ubuntu:~$ sudo apt install build-essential
```

You can use any setup where gcc/g++ (and, later, GTK) is available.

## Test the Environment
Run a simple "hello world" program to double check everything is set and ready.

```c++
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Hello world!" << std::endl;
    return 0;
}
```

Compile just with:
```console
$ gcc -o main main.c -Wall
```

**Suggestion**: Compile with the `-Wall` flag to show up all warning. Also, remember use the `-g` flag to compile with debugging symbols when using a debugger.