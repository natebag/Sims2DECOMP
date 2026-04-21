// 0x8029AF30 (92B) AptDisplayList::removeClonedObject(AptCIH*)

struct AptCIH;
struct EAStringC;

struct AptDisplayListState {
    int findInst(int index, EAStringC* name, AptCIH** out1, AptCIH** out2);
};

struct AptDisplayList {
    AptDisplayListState* m_state;

    void removeObject(AptCIH* obj);
    void removeClonedObject(AptCIH* obj);
};

void AptDisplayList::removeClonedObject(AptCIH* obj) {
    int val = *(int*)((char*)obj + 88);
    int idx = val >> 15;
    AptDisplayListState* state = m_state;
    AptCIH* a = 0;
    AptCIH* b = 0;
    state->findInst(idx, 0, &a, &b);
    removeObject(b);
}
