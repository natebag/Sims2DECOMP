/* ObjFnTableQuickData::AddRef(void) - 0x801102C0 - 20 bytes */
/* mr r9, r3; lwz r3, 0x14(r9); addi r3, r3, 1; stw r3, 0x14(r9); blr */

class ObjFnTableQuickData {
public:
    char _pad[0x14];
    int m_refCount;

    int AddRef(void);
};

int ObjFnTableQuickData::AddRef(void) {
    return ++m_refCount;
}
