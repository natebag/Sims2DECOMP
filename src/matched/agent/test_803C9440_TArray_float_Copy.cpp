// FLAGS: -fno-schedule-insns

void TArray_float_Copy(float* dst, float* src, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        *dst = *src;
        src++;
        dst++;
    } while (i-- != 0);
}
