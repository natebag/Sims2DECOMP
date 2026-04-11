// 0x80321724 ArcFileInfo::ArcFileInfo (32b)

struct ArcFileInfo {
    int f0;
    int f4;
    int f8;
    int f12;
    int f16;
    ArcFileInfo();
};

ArcFileInfo::ArcFileInfo() {
    ArcFileInfo* p = this;
    p->f0 = 0;
    p->f4 = 0;
    p->f8 = 0;
    p->f12 = 0;
    p->f16 = 0;
}
