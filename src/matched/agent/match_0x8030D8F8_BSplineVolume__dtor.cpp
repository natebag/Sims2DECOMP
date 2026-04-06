// 0x8030D8F8 BSplineVolume::~BSplineVolume (76b)

extern int VTable_BSplineVolume[];
extern void __dl__FPv(void*);

struct BSplineVolume {
    char pad[0xDC];
    int* vtable;

    void Free();
    ~BSplineVolume();
};

BSplineVolume::~BSplineVolume() {
    vtable = VTable_BSplineVolume;
    Free();
}
