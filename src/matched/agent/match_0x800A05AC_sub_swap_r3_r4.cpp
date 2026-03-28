/* 44-byte wrapper at 0x800A05AC: swaps r3/r4 and calls */

extern void target_800A05AC(void*, void*);

void sub_800A05AC(void *a, void *b) {
    target_800A05AC(b, a);
}
