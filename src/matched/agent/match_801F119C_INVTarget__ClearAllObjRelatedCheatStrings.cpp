typedef unsigned int size_t;
extern "C" void* memset(void*, int, size_t);

class INVTarget {
public:
    char pad[0x118B];
    char m_objCheatStr1[0x800];
    char m_objCheatStr2[0x800];
    char m_objCheatStr3[0x800];
    void ClearAllObjRelatedCheatStrings(void);
};

void INVTarget::ClearAllObjRelatedCheatStrings(void) {
    memset(m_objCheatStr1, 0, 0x800);
    memset(m_objCheatStr2, 0, 0x800);
    memset(m_objCheatStr3, 0, 0x800);
}
