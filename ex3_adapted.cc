#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

bool FuzzMe(const uint8_t *Data, size_t DataSize) {
	if (DataSize > 3 && *(unsigned int *)Data == 0xdeadeeee)
                       __builtin_trap();
                           return 0;
}


extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  FuzzMe(Data, Size);
  return 0;
}



