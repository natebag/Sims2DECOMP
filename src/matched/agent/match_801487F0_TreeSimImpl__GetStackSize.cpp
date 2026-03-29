// 0x801487F0 (40 bytes)
// TreeSimImpl::GetStackSize(void)
// stwu; mflr; stw; addi r3,r3,12; bl TreeStack::GetStackSize; extsh r3,r3; lwz; mtlr; addi; blr
// Calls m_stack.GetStackSize() then sign-extends result to short

class TreeStack {
public:
    int GetStackSize();
};

class TreeSimImpl {
public:
    char _pad[12];
    TreeStack m_stack;  // offset 12
    short GetStackSize();
};

short TreeSimImpl::GetStackSize() {
    return (short)m_stack.GetStackSize();
}
