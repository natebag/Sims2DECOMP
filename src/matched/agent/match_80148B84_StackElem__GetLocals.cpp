// 0x80148B84 (20 bytes)
// StackElem::GetLocals(void)
// DOL: lbz r9,7(r3); add r9,r9,r9; addi r9,r9,20; add r3,r3,r9; blr
// Compute offset = 2*numLocals+20, then return this+offset

class StackElem {
public:
    char _pad[7];
    unsigned char m_numLocals;  // offset 7
    void* GetLocals();
};

void* StackElem::GetLocals() {
    unsigned int offset = (unsigned int)m_numLocals;
    offset += offset;
    offset += 20;
    return (char*)this + offset;
}
