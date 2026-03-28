/* 44-byte wrapper at 0x80221B7C: swaps r3/r4 and calls */

extern void target_80221B7C(void*, void*);

void sub_80221B7C(void *a, void *b) {
    target_80221B7C(b, a);
}
