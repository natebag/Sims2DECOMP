// 0x800BD968 (32B) IFFResMap::CountTypes(void)
// Pointer-diff element count: (m_end - m_begin) where sizeof(Type) = 24.

struct IFFType { char data[24]; };

class IFFResMap {
public:
    IFFType* m_begin;
    IFFType* m_end;
    int CountTypes();
};

int IFFResMap::CountTypes() {
    return m_end - m_begin;
}
