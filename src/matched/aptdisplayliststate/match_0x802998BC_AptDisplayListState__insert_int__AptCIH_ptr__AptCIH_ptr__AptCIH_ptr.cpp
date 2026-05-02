// 0x802998BC AptDisplayListState::insert(int, AptCIH *, AptCIH *, AptCIH *) (64b)
struct AptCIH {
    char pad[0x58];
    unsigned int depth : 17;
    unsigned int flags : 15;
};

struct AptDisplayListState {
    AptCIH* insert(AptCIH* after, AptCIH* cih);
    AptCIH* insert(int depth, AptCIH* cih, AptCIH* after, AptCIH* before);
};

AptCIH* AptDisplayListState::insert(int depth, AptCIH* cih, AptCIH* after, AptCIH* before) {
    AptCIH* node = insert(after, cih);
    node->depth = depth;
    return node;
}
