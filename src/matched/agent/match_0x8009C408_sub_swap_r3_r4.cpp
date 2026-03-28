/* 44-byte wrapper at 0x8009C408: swaps r3/r4 and calls */

extern void target_8009C408(void*, void*);

void sub_8009C408(void *a, void *b) {
    target_8009C408(b, a);
}
