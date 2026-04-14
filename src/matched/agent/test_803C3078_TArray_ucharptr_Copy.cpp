// FLAGS: -fno-schedule-insns

typedef unsigned char* ucharptr;

void TArray_ucharptr_Copy(ucharptr* dst, ucharptr* src, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        *dst = *src;
        src++;
        dst++;
    } while (i-- != 0);
}
