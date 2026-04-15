// 0x80007438 loadRenderingUnit(void*, int) (20B)
// this->field12 is an array of 8-byte entries; return entry[idx].field4

struct Entry { char pad[4]; void* m_field4; };

struct Unit {
    char pad[12];
    Entry* m_entries;  // +12
};

void* loadRenderingUnit(void* p, int idx) {
    Entry* arr = ((Unit*)p)->m_entries;
    Entry* e = arr + idx;
    return e->m_field4;
}
