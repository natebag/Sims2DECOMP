// FLAGS: -fno-schedule-insns -fno-schedule-insns2
// 0x8004B598 less_int16_t(void *, void *) (36B)
// ASMPROC_swap_adj: a=li b=cmpw which=first

extern "C" int less_int16_t(const short* a, const short* b) {
    short av = *a;
    short bv = *b;
    int result = 0;
    do {
        if (av == bv) break;
        result = 1;
        if (av >= bv) break;
        result = -1;
    } while (0);
    return result;
}
