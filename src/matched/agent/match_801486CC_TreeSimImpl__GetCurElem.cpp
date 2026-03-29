// 0x801486CC (60 bytes)
// TreeSimImpl::GetCurElem(void)
// stmw r30, 8(r1); addi r30, r3, 12; mr r3, r30; bl GetStackSize; addi r4, r3, -1
// mr r3, r30; bl GetNthFrame(r4); lmw r30, 8(r1); return
// GetCurElem = m_stack.GetNthFrame(m_stack.GetStackSize() - 1)

class TreeStack {
public:
    int GetStackSize();
    void* GetNthFrame(int n);
};

class TreeSimImpl {
public:
    char _pad[12];
    TreeStack m_stack;  // offset 12
    void* GetCurElem();
};

void* TreeSimImpl::GetCurElem() {
    int size = m_stack.GetStackSize();
    return m_stack.GetNthFrame(size - 1);
}
