#include "afl.h"

#ifdef __AFL_BASIC_COVERAGE
void afllog (uint16_t i) {
asm (".globl __afl_maybe_log\n\t"
     "movq %0, %%rcx\n\t"
     "call __afl_maybe_log"
     :
     : "r" ((unsigned long long) (i))
     : "rcx", "rdx", "rax");
}
#else
#error "No coverage type selected"
#endif
