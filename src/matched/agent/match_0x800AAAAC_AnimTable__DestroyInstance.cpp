// 0x800AAAAC AnimTable::DestroyInstance(AnimTable*) (64B)

struct AnimTable {
    virtual ~AnimTable();
    static void DestroyInstance(AnimTable* p);
};

void AnimTable::DestroyInstance(AnimTable* p) {
    if (p) {
        delete p;
    }
}
