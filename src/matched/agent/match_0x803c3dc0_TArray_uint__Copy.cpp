// FLAGS: -fno-schedule-insns
/* TArray<unsigned int, TArrayDefaultAllocator>::Copy(unsigned int *, unsigned int *, int) at 0x803C3DC0 (44B) */

struct TArray_UIC {
    static void Copy(unsigned int* dst, unsigned int* src, int count);
};

void TArray_UIC::Copy(unsigned int* dst, unsigned int* src, int count) {
    int n = count - 1;
    if (count != 0) {
        do {
            *dst++ = *src++;
        } while (n-- != 0);
    }
}
