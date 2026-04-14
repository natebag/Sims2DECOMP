// FLAGS: -fno-schedule-insns

struct EFontPage;
typedef EFontPage* EFontPagePtr;

void TArray_EFontPagePtr_Copy(EFontPagePtr* dst, EFontPagePtr* src, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        *dst = *src;
        src++;
        dst++;
    } while (i-- != 0);
}
