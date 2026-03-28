/* 36-byte wrapper at 0x800A7784: shifts r4 to r3 */

extern void target_800A7784(void*);

void sub_800A7784(void *unused, void *arg) {
    target_800A7784(arg);
}
