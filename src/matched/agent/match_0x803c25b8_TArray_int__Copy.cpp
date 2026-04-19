// FLAGS: -fno-schedule-insns
/* TArray<int, TArrayDefaultAllocator>::Copy(int *, int *, int) at 0x803C25B8 (44B) */

struct TArray_IC {
    static void Copy(int* dst, int* src, int count);
};

void TArray_IC::Copy(int* dst, int* src, int count) {
    int n = count - 1;
    if (count != 0) {
        do {
            *dst++ = *src++;
        } while (n-- != 0);
    }
}
