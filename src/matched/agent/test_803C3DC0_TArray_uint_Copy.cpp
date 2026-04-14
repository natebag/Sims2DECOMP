// FLAGS: -fno-schedule-insns

typedef unsigned int uint;

void TArray_uint_Copy(uint* dst, uint* src, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        *dst = *src;
        src++;
        dst++;
    } while (i-- != 0);
}
