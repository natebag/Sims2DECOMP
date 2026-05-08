// FLAGS: -fno-schedule-insns
// 0x800F9620 (72 bytes)
// ObjectModuleImpl::GetObjectFromID(int)

struct ObjectModuleImpl_GOFI {
    char pad[8336];
    void** m_objectsBegin;
    void** m_objectsEnd;
    void* GetObjectFromID(int id);
};

void* ObjectModuleImpl_GOFI::GetObjectFromID(int id) {
    register void** begin asm("r11");
    void** end;
    int count;
    if (id <= 0) goto null_exit;
    begin = m_objectsBegin;
    end = m_objectsEnd;
    count = (int)(end - begin);
    if (id <= count) goto proceed;
null_exit:
    return 0;
proceed:
    {
        register int idx asm("r9") = id - 1;
        register void* result asm("r3") = 0;
        register void* obj asm("r4");
        idx <<= 2;
        obj = *(void**)((char*)begin + idx);
        if (!obj) return result;
        return *(void**)((char*)obj + 4);
    }
}
