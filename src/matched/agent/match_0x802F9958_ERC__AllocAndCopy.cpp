typedef unsigned char u8;

u8* allocMem(u8*, int, int);
void memcpy_func(u8*, u8*, int);

u8* ERC_AllocAndCopy(u8* src, u8* data, int size) {
    if (data == 0) return 0;
    u8* dest = allocMem(src, size, 32);
    memcpy_func(dest, data, size);
    return dest;
}
