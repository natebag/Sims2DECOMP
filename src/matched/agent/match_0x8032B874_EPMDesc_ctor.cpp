// 0x8032B874 EPMDesc::EPMDesc (36b)

struct EPMDesc {
    int f0;
    int f4;
    int f8;
    int f12;
    int f16;
    EPMDesc(int p2, int p3);
};

EPMDesc::EPMDesc(int p2, int p3) {
    EPMDesc* p = this;
    p->f0 = p2;
    p->f4 = 0;
    p->f8 = -1;
    p->f16 = 0;
    p->f12 = p3;
}
