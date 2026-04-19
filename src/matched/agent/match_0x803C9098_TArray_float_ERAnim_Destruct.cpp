// FLAGS: -fno-schedule-insns
// 0x803C9098 (28B) TArray POD template clone: TArray_float_ERAnim_Destruct
// Empty-body decrement loop. Identical bytes to 0x8039C3F0 anchor.

void Destruct_POD_803C9098(int*, int count) {
    register int i asm("r9") = count - 1;
    if (count == 0) return;
    do { } while (i--);
}
