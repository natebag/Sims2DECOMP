// FLAGS: -fno-schedule-insns
// 0x800F97CC (84 bytes)
// ObjectModuleImpl::GetObject(int)

struct ObjMod_GO {
    char pad8336[8336];
    void** m_objectsBegin;     // offset 8336 (far path)
    char pad8340[8];
    void* m_compactTable[16];  // offset 8352 (near path, IDs 0x4000..0x400F)

    void* GetObject(int id);
};

void* ObjMod_GO::GetObject(int id) {
    register unsigned int offset asm("r0") = (unsigned int)(id - 0x4000);
    if (offset > 15) {
        void** begin = m_objectsBegin;
        unsigned int byte_idx = (unsigned int)id << 2;
        register void* result asm("r0") = 0;
        register void* obj asm("r3") = *(void**)((char*)begin + byte_idx);
        if (obj) result = *(void**)((char*)obj + 4);
        return result;
    }
    offset <<= 2;
    void** base = (void**)((char*)this + 8352);
    register void* obj asm("r3") = *(void**)((char*)base + offset);
    register void* result asm("r0") = 0;
    if (obj) result = *(void**)((char*)obj + 4);
    return result;
}
