// FLAGS: -fno-schedule-insns
/* TArray<unsigned char *, TArrayDefaultAllocator>::Copy(unsigned char **, unsigned char **, int) at 0x803C3078 (44B) */

struct TArray_UCP {
    static void Copy(unsigned char** dst, unsigned char** src, int count);
};

void TArray_UCP::Copy(unsigned char** dst, unsigned char** src, int count) {
    int n = count - 1;
    if (count != 0) {
        do {
            *dst++ = *src++;
        } while (n-- != 0);
    }
}
