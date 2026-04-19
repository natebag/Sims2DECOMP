// FLAGS: -fno-schedule-insns
// 0x803C3DA4 (28B) TArray POD template clone: TArray_uint_Construct
// Empty-body decrement loop. Identical bytes to 0x8039C3F0 anchor.

void Destruct_POD_803C3DA4(int*, int count) {
    register int i asm("r9") = count - 1;
    if (count == 0) return;
    do { } while (i--);
}
