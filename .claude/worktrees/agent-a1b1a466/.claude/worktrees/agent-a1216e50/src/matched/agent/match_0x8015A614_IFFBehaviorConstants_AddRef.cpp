/* IFFBehaviorConstants::AddRef(void) - 0x8015A614 - 20 bytes */

class IFFBehaviorConstants {
public:
    char _pad[0x60];
    int m_refCount;

    int AddRef(void);
};

int IFFBehaviorConstants::AddRef(void) {
    return ++m_refCount;
}
