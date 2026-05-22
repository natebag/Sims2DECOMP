// 0x802E0D24 EMemoryWriteStream::operator[](int) (44B)
// ASMPROC_swap_adj: a="lwz" b="srawi" which=first
// ASMPROC_swap_operands: match="lwzx 3,9,11" pos="1,2"

struct EMemoryWriteStream {
    char pad[0x20];
    void* pages;
    char* operator[](int idx);
};

char* EMemoryWriteStream::operator[](int idx) {
    register int page asm("r9") = idx;
    if (idx < 0) page = idx + 4095;
    page = page >> 12;
    void** p = (void**)pages;
    return (char*)p[page] + (idx & 0xFFF);
}
