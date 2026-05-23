// 0x80162028 CasMediator::GetListenerCount(void) const (8B) — class-scope upgrade
//
// Body:  lwz r3, 8(r3); blr  — int getter for field at offset 0x8
//
// Symbol absent from release/debug map (likely inlined elsewhere or unnamed).
// Inferred semantic: offset 0x8 of CasMediator inherits from CasListenerSet
// base where it corresponds to _M_node_count (per CasMediator::AddListener
// layout @ 0x80161D18). Hence "GetListenerCount" is the most likely real
// method name — flagged as inferred (not map-confirmed).

class CasMediator {
public:
    char pad[0x8];
    int m_listenerCount;
    int GetListenerCount(void) const;
};

int CasMediator::GetListenerCount(void) const {
    return m_listenerCount;
}
