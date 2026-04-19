// FLAGS: -fno-schedule-insns
// 0x803C7F28 (44B) TArray<EFontPage*, TArrayDefaultAllocator>::Copy(EFontPage**, EFontPage**, int)
// POD 4-byte (pointer) element copy loop.

void Copy_POD_EFontPagePtr(int* dst, int* src, int count) {
    register int i asm("r9") = count - 1;
    if (count == 0) return;
    do {
        *dst = *src;
        src++;
        dst++;
    } while (i-- != 0);
}
