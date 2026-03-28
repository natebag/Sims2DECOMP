/* 44-byte wrapper at 0x80221BA8: swaps r3/r4 and calls */

extern void target_80221BA8(void*, void*);

void sub_80221BA8(void *a, void *b) {
    target_80221BA8(b, a);
}
