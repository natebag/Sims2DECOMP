/* 44-byte wrapper at 0x802256A4: swaps r3/r4 and calls */

extern void target_802256A4(void*, void*);

void sub_802256A4(void *a, void *b) {
    target_802256A4(b, a);
}
