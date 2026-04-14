// 0x801487CC (36 bytes)
// TreeSimImpl::GetNthElem(short)
// stwu r1,-8; mflr r0; stw r0,12; addi r3,r3,12; bl GetNthFrame; lwz r0,12; mtlr; addi r1,8; blr
// Calls TreeStack::GetNthFrame(r4) with this->m_stack (at offset 12)

class TreeStack {
public:
    void* GetNthFrame(int n);
};

class TreeSimImpl {
public:
    char _pad[12];
    TreeStack m_stack;  // offset 12
    void* GetNthElem(short n);
};

void* TreeSimImpl::GetNthElem(short n) {
    return m_stack.GetNthFrame(n);
}
