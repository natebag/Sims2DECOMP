/* 36-byte wrapper at 0x802296C0: shifts r4 to r3 */

extern void target_802296C0(void*);

void sub_802296C0(void *unused, void *arg) {
    target_802296C0(arg);
}
