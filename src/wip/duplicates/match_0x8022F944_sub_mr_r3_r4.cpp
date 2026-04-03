/* 36-byte wrapper at 0x8022F944: shifts r4 to r3 */

extern void target_8022F944(void*);

void sub_8022F944(void *unused, void *arg) {
    target_8022F944(arg);
}
