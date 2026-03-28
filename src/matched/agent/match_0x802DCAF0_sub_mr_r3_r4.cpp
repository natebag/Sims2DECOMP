/* 36-byte wrapper at 0x802DCAF0: shifts r4 to r3 */

extern void target_802DCAF0(void*);

void sub_802DCAF0(void *unused, void *arg) {
    target_802DCAF0(arg);
}
