// 0x800C8E10 Neighbor::Neighbor(Neighbor&) copy ctor (132B)

struct Neighbor {
    char pad[40];
    char stackstr[232];  // 40..271
    char other[132];      // 272..403
    void* m_items;        // offset 404

    Neighbor(Neighbor& o);
};

extern "C" void StackString_Init(void* self, void* buf, int size);  // 0x800a65ac
extern "C" void OtherCtor(void* p);                                   // 0x800c27fc
extern "C" void* OpNew(int size);                                     // 0x802d11e8
extern "C" void ItemInit(void* item);                                  // 0x8014ab70
extern "C" void Neighbor_CopyFromOther(Neighbor* self, Neighbor* o);   // 0x800c8e94

Neighbor::Neighbor(Neighbor& o) {
    StackString_Init((char*)this + 40, (char*)this + 48, 64);
    OtherCtor((char*)this + 272);
    char* arr = (char*)OpNew(240);
    char* cur = arr;
    int n = 19;
    do {
        ItemInit(cur);
        cur += 12;
    } while (n-- != 0);
    m_items = arr;
    Neighbor_CopyFromOther(this, &o);
}
