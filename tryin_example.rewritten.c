#include <setjmp.h>
#include "deadline.h"

jmp_buf PRET_jmpbuf_0;
jmp_buf PRET_jmpbuf_1;
void main() {
    register_jmpbuf(0, &PRET_jmpbuf_0);
    register_jmpbuf(1, &PRET_jmpbuf_1);

    if (_setjmp(PRET_jmpbuf_1) == 0) { /* tryin block */
        DEADLOAD0(300000000000 /* 5 minutes */);
        DEADLOADBRANCH1( 30000000000 /* 30 seconds */) ;
        for (;;) {
            beat_eggs();
        }
        DEADLOAD1(0);
        DEADLOAD0(0);
    } else { /* catch block */
        put_eggs_in_pan();
    }
    remove_eggs_from_pan();
}
