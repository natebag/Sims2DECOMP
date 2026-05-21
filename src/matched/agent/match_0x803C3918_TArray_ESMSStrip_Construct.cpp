// 0x803C3918 TArray<ESMSStrip, TArrayERModelAllocator>::Construct(ESMSStrip*, int) (112 B)
// FLAGS: -fno-schedule-insns

struct ESMSStrip {
    int a, b, c, d, e, f, g, h, i;
    unsigned char j, k, l, m;
    short n;
    unsigned char o, p;
    int q;
    unsigned char r;
};

void TArray_ESMSStrip_Construct(ESMSStrip* dst, int count) {
    int i = count - 1;
    if (count == 0) return;
    do {
        dst++;
        dst[-1].a = 0;
        dst[-1].b = 0;
        dst[-1].c = 0;
        dst[-1].d = 0;
        dst[-1].e = 0;
        dst[-1].f = 0;
        dst[-1].g = 0;
        dst[-1].h = 0;
        dst[-1].i = 0;
        dst[-1].j = 0xFF;
        dst[-1].k = 0xFF;
        dst[-1].l = 0xFF;
        dst[-1].m = 0xFF;
        dst[-1].n = 0;
        dst[-1].p = 0;
        dst[-1].o = 0;
        dst[-1].q = 0;
        dst[-1].r = 0;
    } while (i-- != 0);
}
