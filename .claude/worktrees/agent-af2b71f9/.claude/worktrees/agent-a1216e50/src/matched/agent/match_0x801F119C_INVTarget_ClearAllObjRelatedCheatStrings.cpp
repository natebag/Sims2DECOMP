/* INVTarget::ClearAllObjRelatedCheatStrings - 0x801F119C - 88 bytes */

extern "C" void *memset(void *, int, unsigned int);

struct INVTarget {
    char pad[0x118B];
    char m_cheatStr1[0x800];
    char m_cheatStr2[0x800];
    char m_cheatStr3[0x800];
    void ClearAllObjRelatedCheatStrings(void);
};

void INVTarget::ClearAllObjRelatedCheatStrings(void)
{
    memset(m_cheatStr1, 0, 0x800);
    memset(m_cheatStr2, 0, 0x800);
    memset(m_cheatStr3, 0, 0x800);
}
