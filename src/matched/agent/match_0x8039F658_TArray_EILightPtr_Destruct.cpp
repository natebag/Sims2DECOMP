// FLAGS: -fno-schedule-insns
// 0x8039F658 (28B) TArray POD template clone: TArray_EILightPtr_Destruct
// Empty-body decrement loop. Identical bytes to 0x8039C3F0 anchor.

void Destruct_POD_8039F658(int*, int count) {
    register int i asm("r9") = count - 1;
    if (count == 0) return;
    do { } while (i--);
}
