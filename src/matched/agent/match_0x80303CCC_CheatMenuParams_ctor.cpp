// 0x80303CCC CheatMenuParams::CheatMenuParams (24b)

struct CheatMenuParams {
    int f0;
    int f4;
    int f8;
    CheatMenuParams();
};

CheatMenuParams::CheatMenuParams() {
    CheatMenuParams* p = this;
    p->f4 = 0;
    p->f0 = 0;
    p->f8 = 0;
}
