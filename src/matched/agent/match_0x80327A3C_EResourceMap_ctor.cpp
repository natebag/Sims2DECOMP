// 0x80327A3C EResourceMap::EResourceMap (32b)

struct EResourceMap {
    int f0;
    int f4;
    int f8;
    int f12;
    int f16;
    EResourceMap();
};

EResourceMap::EResourceMap() {
    EResourceMap* p = this;
    p->f0 = 0;
    p->f4 = 0;
    p->f8 = 0;
    p->f12 = 0;
    p->f16 = 0;
}
