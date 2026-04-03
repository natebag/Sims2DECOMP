/* ObjFnTableQuickData::AddRef(void) - 0x801102C0 - 20 bytes */

struct ObjFnTableQuickData {
    char _pad[20];
    int m_refCount;

    int AddRef();
};

int ObjFnTableQuickData::AddRef() {
    return ++m_refCount;
}
