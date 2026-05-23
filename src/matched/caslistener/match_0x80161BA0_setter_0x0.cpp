// 0x80161BA0 CasListener::SetMediator(CasMediator*) (8B) — semantic conversion
//
// stw r4, 0(r3); blr  — store mediator pointer into m_pMediator at offset 0
//
// Layout matches CasListener ctor (0x80161B50): m_pMediator at offset 0,
// vtable pointer at offset 4 (manual-vtable struct pattern, not C++ virtual).

class CasMediator;
class CasListener {
public:
    CasMediator* m_pMediator;
    int* m_vtable;
    void SetMediator(CasMediator* mediator);
};

void CasListener::SetMediator(CasMediator* mediator) {
    m_pMediator = mediator;
}
