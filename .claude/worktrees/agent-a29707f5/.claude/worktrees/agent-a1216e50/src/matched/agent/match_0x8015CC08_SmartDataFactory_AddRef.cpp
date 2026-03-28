/* SmartDataFactory::AddRef(void) - 0x8015CC08 - 20 bytes */

class SmartDataFactory {
public:
    char _pad[0x14];
    int m_refCount;

    int AddRef(void);
};

int SmartDataFactory::AddRef(void) {
    return ++m_refCount;
}
