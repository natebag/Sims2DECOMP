// 0x80147928 (56 bytes)
// TreeSimImpl::Initialize(int, short*)
// stmw r29; mr r30,r3; mr r29,r5; addi r3,r30,12; bl TreeStack::Initialize(r4)
// stw r29, 48(r30); lmw r29; blr

class TreeStack {
public:
    void Initialize(int n);
};

class TreeSimImpl {
public:
    char _pad[12];
    TreeStack m_stack;   // offset 12
    char _pad2[32];      // padding to reach offset 48
    short* m_field48;    // offset 48 = 0x30
    void Initialize(int n, short* x);
};

void TreeSimImpl::Initialize(int n, short* x) {
    m_stack.Initialize(n);
    m_field48 = x;
}
