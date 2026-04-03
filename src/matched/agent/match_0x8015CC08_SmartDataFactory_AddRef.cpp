/* SmartDataFactory::AddRef(void) - 0x8015CC08 - 20 bytes */

struct SmartDataFactory {
    char _pad[20];
    int m_refCount;

    int AddRef();
};

int SmartDataFactory::AddRef() {
    return ++m_refCount;
}
