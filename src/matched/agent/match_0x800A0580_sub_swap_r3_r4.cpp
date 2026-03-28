/* 44-byte wrapper at 0x800A0580: swaps r3/r4 and calls */

extern void target_800A0580(void*, void*);

void sub_800A0580(void *a, void *b) {
    target_800A0580(b, a);
}
