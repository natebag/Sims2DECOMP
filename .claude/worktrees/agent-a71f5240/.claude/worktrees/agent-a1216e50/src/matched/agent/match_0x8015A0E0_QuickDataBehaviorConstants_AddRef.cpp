/* QuickDataBehaviorConstants::AddRef(void) - 0x8015A0E0 - 20 bytes */

class QuickDataBehaviorConstants {
public:
    char _pad[0x1C];
    int m_refCount;

    int AddRef(void);
};

int QuickDataBehaviorConstants::AddRef(void) {
    return ++m_refCount;
}
