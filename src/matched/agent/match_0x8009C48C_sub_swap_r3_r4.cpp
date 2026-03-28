/* 44-byte wrapper at 0x8009C48C: swaps r3/r4 and calls */

extern void target_8009C48C(void*, void*);

void sub_8009C48C(void *a, void *b) {
    target_8009C48C(b, a);
}
