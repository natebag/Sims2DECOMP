// 0x80112048 ObjTestSim::ObjTestSim (24b)

struct cXPerson;

struct ObjTestSim {
    cXPerson* f0;
    int f4;
    int pad[4];  // padding to ensure f24 is at offset 24
    int f24;     // at offset 0x18 (24)
    ObjTestSim(cXPerson* p2);
};

ObjTestSim::ObjTestSim(cXPerson* p2) {
    ObjTestSim* p = this;
    p->f0 = p2;
    p->f4 = 0;
    p->f24 = 0;
}
