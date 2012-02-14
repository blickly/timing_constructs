#include <setjmp.h>
#include "deadline.h"

jmp_buf PRET_jmpbuf_0;
jmp_buf PRET_jmpbuf_1;
void main() {
    register_jmpbuf(0, &PRET_jmpbuf_0);
    register_jmpbuf(1, &PRET_jmpbuf_1);

PRET_timedloop_start_1:
    if (_setjmp(PRET_jmpbuf_1) == 0) { /* no exception */
        for (;;) {
            DEADLOAD1(0);
            DEAD0(86400000000000 /* 24 hours */);
            DEADLOADBRANCH1( 3600000000000 /* 1 hour */) ;
            run_cron_job();
        }
    } else { /* catch block */
        log("Error: cron job executed for over an hour and was terminated");
        goto PRET_timedloop_start_1;
    }
}
