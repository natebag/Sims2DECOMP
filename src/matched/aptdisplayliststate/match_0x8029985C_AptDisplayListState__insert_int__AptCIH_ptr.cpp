// 0x8029985C AptDisplayListState::insert(int, AptCIH *) (96b)
struct EAStringC;

struct AptCIH {
    char pad[0x58];
    unsigned int depth : 17;
    unsigned int flags : 15;
};

struct AptDisplayListState {
    void findInst(int depth, EAStringC* name, AptCIH** prev, AptCIH** found);
    AptCIH* insert(AptCIH* after, AptCIH* cih);
    AptCIH* insert(int depth, AptCIH* cih);
};

AptCIH* AptDisplayListState::insert(int depth, AptCIH* cih) {
    AptCIH* prev;
    AptCIH* found;
    findInst(depth, 0, &prev, &found);
    AptCIH* node = insert(prev, cih);
    node->depth = depth;
    return node;
}
