// 0x80143814 SlotLoader::SlotLoader (20b)

struct SlotLoader {
    int f0;
    short f4;
    SlotLoader(int p2);
};

SlotLoader::SlotLoader(int p2) {
    SlotLoader* p = this;
    p->f0 = p2;
    p->f4 = 0;
}
