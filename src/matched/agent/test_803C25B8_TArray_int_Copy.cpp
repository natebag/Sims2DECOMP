// FLAGS: -fno-schedule-insns

void TArray_int_Copy(int* dst, int* src, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        *dst = *src;
        src++;
        dst++;
    } while (i-- != 0);
}
