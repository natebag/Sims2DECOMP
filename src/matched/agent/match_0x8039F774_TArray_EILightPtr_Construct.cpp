// FLAGS: -fno-schedule-insns
// 0x8039F774 (28B) TArray POD template clone: TArray_EILightPtr_Construct
// Empty-body decrement loop. Identical bytes to 0x8039C3F0 anchor.

void Destruct_POD_8039F774(int*, int count) {
    register int i asm("r9") = count - 1;
    if (count == 0) return;
    do { } while (i--);
}
