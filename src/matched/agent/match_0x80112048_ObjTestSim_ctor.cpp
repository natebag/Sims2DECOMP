// 0x80112048 ObjTestSim::ObjTestSim (24b)

struct ObjTestSim {
    int f0;
    int f4;
    int f8;
    int f12;
    int f16;
    int f20;
    int f24;
    ObjTestSim(int p2);
};

ObjTestSim::ObjTestSim(int p2) {
    ObjTestSim* p = this;
    p->f0 = p2;
    p->f4 = 0;
    p->f24 = 0;
}
