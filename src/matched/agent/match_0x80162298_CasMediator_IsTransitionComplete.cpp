// 0x80162298 CasMediator::IsTransitionComplete(void) (92B)
// Two-stage gate predicate: NaN-loose `<` + NaN-strict `<=`.
// Returns 1 (xori from r0=0) unless m_aa8 < 1.0 AND m_aac <= 0.0.
// Shared return-1 path between the two null checks via short-circuit OR.

struct CasMediatorTransition {
    char pad[0xaa8];
    float m_field_aa8;
    float m_field_aac;
};

class CasMediator {
public:
    char pad[0x14];
    int m_field14;
    CasMediatorTransition* m_field18;
    int IsTransitionComplete();
};

int CasMediator::IsTransitionComplete() {
    if (m_field14 == 0 || m_field18 == 0) return 1;
    CasMediatorTransition* tr = m_field18;
    int result = 0;
    if (tr->m_field_aa8 < 1.0f) {
        if (tr->m_field_aac <= 0.0f) {
            result = 1;
        }
    }
    return result ^ 1;
}
