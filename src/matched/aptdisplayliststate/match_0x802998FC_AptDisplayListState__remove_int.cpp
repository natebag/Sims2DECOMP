// 0x802998FC AptDisplayListState::remove(int) (52b)
struct EAStringC;

struct AptCIH {
    void remove();
};

struct AptDisplayListState {
    void findInst(int depth, EAStringC* name, AptCIH** prev, AptCIH** found);
    void remove(int depth);
};

void AptDisplayListState::remove(int depth) {
    AptCIH* prev;
    AptCIH* found;
    findInst(depth, 0, &prev, &found);
    found->remove();
}
