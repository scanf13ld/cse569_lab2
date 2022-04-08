#include <unistd.h>
#include <stdio.h>
#include <string.h>

// ex1.cc
  int main(int argc, char *argv[]) {
    char data[100] = {0};
    size_t size = read(0, data, 100);

    if (size > 0 && data[0] == 'H')
      if (size > 1 && data[1] == 'I')
         if (size > 2 && data[2] == '!')
         __builtin_trap();

    write(1, data, 100);
    return 0;
  }

