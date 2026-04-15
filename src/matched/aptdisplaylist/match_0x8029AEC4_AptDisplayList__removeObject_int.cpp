/* AptDisplayList::removeObject(int) - 0x8029AEC4 (72B) */

struct AptCIH;
struct EAStringC;

struct AptDisplayListState {
    int findInst(int id, EAStringC* str, AptCIH** outA, AptCIH** outB);
};

class AptDisplayList {
public:
    AptDisplayListState* m_state;  // +0

    void removeObject(int n);
    void removeObject(AptCIH* cih);
};

void AptDisplayList::removeObject(int n) {
    AptCIH* a;
    AptCIH* b;
    m_state->findInst(n, 0, &a, &b);
    removeObject(b);
}
