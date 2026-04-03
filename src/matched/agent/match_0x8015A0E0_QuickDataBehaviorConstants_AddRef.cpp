/* QuickDataBehaviorConstants::AddRef(void) - 0x8015A0E0 - 20 bytes */

struct QuickDataBehaviorConstants {
    char _pad[28];
    int m_refCount;

    int AddRef();
};

int QuickDataBehaviorConstants::AddRef() {
    return ++m_refCount;
}
