/* ResourceBehavior::AddRef(void) - 0x800ACBB4 - 20 bytes */

struct ResourceBehavior {
    char _pad[28];
    int m_refCount;

    int AddRef();
};

int ResourceBehavior::AddRef() {
    return ++m_refCount;
}
