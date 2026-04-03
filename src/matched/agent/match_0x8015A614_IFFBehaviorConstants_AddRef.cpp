/* IFFBehaviorConstants::AddRef(void) - 0x8015A614 - 20 bytes */

struct IFFBehaviorConstants {
    char _pad[96];
    int m_refCount;

    int AddRef();
};

int IFFBehaviorConstants::AddRef() {
    return ++m_refCount;
}
