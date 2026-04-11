// 0x803622B4 MdfData::MdfData (52b)

struct MdfData {
    int f0;
    int f4;
    int f8;
    int f12;
    int f16;
    int f20;
    int f24;
    int f28;
    int f32;
    int f36;
    MdfData();
};

MdfData::MdfData() {
    MdfData* p = this;
    p->f0 = 0;
    p->f4 = 0;
    p->f8 = 0;
    p->f12 = 0;
    p->f16 = 0;
    p->f20 = 0;
    p->f24 = 0;
    p->f28 = 0;
    p->f32 = 0;
    p->f36 = 0;
}
