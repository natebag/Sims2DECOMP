// FLAGS: -fno-schedule-insns
/* TArray<float, TArrayERAnimAllocator>::Copy(float *, float *, int) at 0x803C9440 (44B) */

struct TArray_FC {
    static void Copy(float* dst, float* src, int count);
};

void TArray_FC::Copy(float* dst, float* src, int count) {
    int* idst = (int*)dst;
    int* isrc = (int*)src;
    int n = count - 1;
    if (count != 0) {
        do {
            *idst++ = *isrc++;
        } while (n-- != 0);
    }
}
