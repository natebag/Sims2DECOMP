// 0x80148B98 (28 bytes)
// StackElem::GetSize(void) const
// lbz r0,7(r3); lbz r3,6(r3); add r3,r3,r0; addi r3,r3,3
// rlwinm r3,r3,1,21,28; addi r3,r3,20; blr
// Size = ((byte6 + byte7 + 3) * 2) & 0x7F8 + 20

class StackElem {
public:
    char _pad[6];
    unsigned char m_numParams;  // offset 6
    unsigned char m_numLocals;  // offset 7
    int GetSize() const;
};

int StackElem::GetSize() const {
    unsigned int n = (unsigned int)m_numParams + m_numLocals + 3;
    return (int)((n * 2) & 0x7F8) + 20;
}
