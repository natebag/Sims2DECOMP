// 0x80299264 AptPseudoDisplayList::Remove(int) (64b)
struct AptPseudoCIH_t;

struct AptPseudoDisplayList {
    void FindInst(int depth, AptPseudoCIH_t** prev, AptPseudoCIH_t** found);
    void Remove(AptPseudoCIH_t* cih);
    void Remove(int depth);
};

void AptPseudoDisplayList::Remove(int depth) {
    AptPseudoCIH_t* prev;
    AptPseudoCIH_t* found;
    FindInst(depth, &prev, &found);
    Remove(found);
}
