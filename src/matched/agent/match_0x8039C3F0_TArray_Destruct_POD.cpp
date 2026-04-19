// FLAGS: -fno-schedule-insns
// 0x8039C3F0 (28B) TArray<int, TArrayERCharacterAllocator>::Destruct(int*, int)
// Empty-body decrement loop for POD type.

void Destruct_POD(int*, int count) {
    register int i asm("r9") = count - 1;
    if (count == 0) return;
    do { } while (i--);
}
