// 0x80321430 ArcCopier::ArcCopier (28b)

struct ArcCopier {
    int f0;
    int f4;
    int f8;
    int f12;
    ArcCopier();
};

ArcCopier::ArcCopier() {
    ArcCopier* p = this;
    p->f0 = 0;
    p->f4 = 0;
    p->f8 = 0;
    p->f12 = 0;
}
