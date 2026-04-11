// TreeTableQuickData::Release(void) - 0x8015E500 - 92 bytes
// COM-style reference counting with virtual destructor dispatch

class TreeTableQuickData {
public:
    void* __vtable;      // +0x00
    char _pad[0x1C];     // +0x04 to +0x1F
    int m_refCount;      // +0x20

    int Release();
};

int TreeTableQuickData::Release() {
    int count = --m_refCount;
    if (count == 0) {
        if (this != 0) {
            // Virtual destructor dispatch via vtable
            // vtable+264 contains this offset, vtable+268 contains function pointer
            void** vtable = *(void***)this;
            short offset = *(short*)((char*)vtable + 264);
            void (*dtor)(void*, int) = (void (*)(void*, int))vtable[67]; // 268/4 = 67
            dtor((char*)this + offset, 3); // 3 = deleting destructor flag
        }
        return 0;
    }
    return count;
}
