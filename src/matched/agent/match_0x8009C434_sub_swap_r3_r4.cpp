/* 44-byte wrapper at 0x8009C434: swaps r3/r4 and calls */

extern void target_8009C434(void*, void*);

void sub_8009C434(void *a, void *b) {
    target_8009C434(b, a);
}
