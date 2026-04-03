/* IFFBehavior::AddRef(void) - 0x800AD020 - 20 bytes */

struct IFFBehavior {
    char _pad[16];
    int m_refCount;

    int AddRef();
};

int IFFBehavior::AddRef() {
    return ++m_refCount;
}
