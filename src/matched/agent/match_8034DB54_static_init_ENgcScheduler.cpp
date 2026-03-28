/* 0x8034DB54 (84 bytes) - __static_initialization_and_destruction_0 */

extern char _ngcSched[];

void ENgcScheduler_ctor(void*);
void ENgcScheduler_dtor(void*, int);

void __static_initialization_and_destruction_0_142(int initialize, int priority) {
    if (priority != 0xFFFF) {
        return;
    }

    if (initialize != 0) {
        ENgcScheduler_ctor(_ngcSched);
    } else {
        ENgcScheduler_dtor(_ngcSched, 2);
    }
}
