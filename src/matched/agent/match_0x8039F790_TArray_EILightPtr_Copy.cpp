// FLAGS: -fno-schedule-insns
// 0x8039F790 (44B) TArray<EILight*, TArrayDefaultAllocator>::Copy(EILight**, EILight**, int)
// POD 4-byte (pointer) element copy loop.

void Copy_POD_EILightPtr(int* dst, int* src, int count) {
    register int i asm("r9") = count - 1;
    if (count == 0) return;
    do {
        *dst = *src;
        src++;
        dst++;
    } while (i-- != 0);
}
