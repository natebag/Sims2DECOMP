// 0x8001ECAC (72 bytes) — VERIFIED MATCH
// ECheats::ECheats(void)
// Zeros 256 bytes, calls EmptyLookupList(), stores 0 at offset 260

struct ECheats_C {
    char m_data[256];
    int m_field;
    void EmptyLookupList();
    ECheats_C();
};

extern void memset(void* ptr, int val, unsigned int size);

ECheats_C::ECheats_C() {
    memset(this, 0, 256);
    EmptyLookupList();
    *(int*)((char*)this + 260) = 0;
}
