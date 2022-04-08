#include <unistd.h>
#include <stdio.h>
#include <string.h>

// ex3.cc
     int main(int argc, char *argv[]) {
         char data[100] = {0};
             size_t size = read(0, data, 100);
                if (size > 3 && *(unsigned int *)data == 0xdeadeeee)
                       __builtin_trap();
                           return 0;
                             }
