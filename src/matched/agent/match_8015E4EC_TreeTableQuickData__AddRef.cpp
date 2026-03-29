/* TreeTableQuickData::AddRef(void) - 0x8015E4EC - 20 bytes */
/* or r9,r3,r3; lwz r3,32(r9); addi r3,r3,1; stw r3,32(r9); blr */

class TreeTableQuickData {
public:
    char _pad[0x20];
    int m_refCount;

    int AddRef(void);
};

int TreeTableQuickData::AddRef(void) {
    return ++m_refCount;
}