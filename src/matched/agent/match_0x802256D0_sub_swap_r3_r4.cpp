/* 44-byte wrapper at 0x802256D0: swaps r3/r4 and calls */

extern void target_802256D0(void*, void*);

void sub_802256D0(void *a, void *b) {
    target_802256D0(b, a);
}
