// FLAGS: -fno-schedule-insns
// 0x8039C43C (44B) TArray<int, TArrayERCharacterAllocator>::Copy(int*, int*, int)
// POD 4-byte element copy loop.

void Copy_POD(int* dst, int* src, int count) {
    register int i asm("r9") = count - 1;
    if (count == 0) return;
    do {
        *dst = *src;
        src++;
        dst++;
    } while (i-- != 0);
}
