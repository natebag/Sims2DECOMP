// 0x80161BA8 CasListener::GetMediator(void) (8B) — semantic conversion
//
// lwz r3, 0(r3); blr  — load mediator pointer from m_pMediator at offset 0
//
// Twin of SetMediator (0x80161BA0). Layout matches CasListener ctor (0x80161B50):
// m_pMediator at offset 0, vtable pointer at offset 4.

class CasMediator;
class CasListener {
public:
    CasMediator* m_pMediator;
    int* m_vtable;
    CasMediator* GetMediator(void);
};

CasMediator* CasListener::GetMediator(void) {
    return m_pMediator;
}
