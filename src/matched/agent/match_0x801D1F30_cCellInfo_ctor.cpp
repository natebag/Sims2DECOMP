// 0x801D1F30 cCellInfo::cCellInfo (36b)

struct cCellInfo {
    int f0;
    int f4;
    int f8;
    int f12;
    int f16;
    int f20;
    cCellInfo();
};

cCellInfo::cCellInfo() {
    cCellInfo* p = this;
    p->f0 = 0;
    p->f4 = 0;
    p->f8 = 0;
    p->f12 = 0;
    p->f16 = 0;
    p->f20 = 0;
}
