// FLAGS: -fno-schedule-insns
// 0x803C305C (28B) TArray POD template clone: TArray_ucharPtr_Construct
// Empty-body decrement loop. Identical bytes to 0x8039C3F0 anchor.

void Destruct_POD_803C305C(int*, int count) {
    register int i asm("r9") = count - 1;
    if (count == 0) return;
    do { } while (i--);
}
