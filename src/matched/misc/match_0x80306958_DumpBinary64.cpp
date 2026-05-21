// 0x80306958 DumpBinary64(void *, int) (32B)

void DumpBinary64(void* buf, int n) {
    n = (int)((unsigned int)n >> 3);
    if (n-- == 0) return;
    do {} while (n-- != 0);
}
