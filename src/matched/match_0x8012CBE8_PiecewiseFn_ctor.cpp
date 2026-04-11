// 0x8012CBE8 (28 bytes)
// PiecewiseFn::PiecewiseFn()

struct PiecewiseFn {
    int f0;   // offset 0
    int f4;   // offset 4
    int f8;   // offset 8
    int f12;  // offset 12
    
    PiecewiseFn();
};

PiecewiseFn::PiecewiseFn() {
    volatile PiecewiseFn* p = this;  // Force mr r9, r3
    p->f4 = 0;
    p->f8 = 0;
    p->f12 = 0;
    p->f0 = 0;
}
