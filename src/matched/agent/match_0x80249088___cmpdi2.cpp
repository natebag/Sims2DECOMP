// __cmpdi2 - 0x80249088 (60 bytes)
// libgcc.a(_cmpdi2.o) — SN Systems ProDG libgcc routine
//
// Tier 1 anti_tail_merge canary candidate (instance #2 with EBitArray::Get).
// Source from GCC libgcc _cmpdi2.c — word-by-word 64-bit compare.
//
// FLAGS: -msdata=eabi -G 8

typedef long long DItype;
typedef unsigned long long UDItype;
typedef int SItype;
typedef unsigned int USItype;
typedef int word_type;

struct DIstruct { SItype high; USItype low; };
typedef union { struct DIstruct s; DItype ll; } DIunion;

word_type __cmpdi2(DItype a, DItype b) {
    DIunion ax, bx;
    ax.ll = a;
    bx.ll = b;

    if (ax.s.high < bx.s.high)
        return 0;
    else if (ax.s.high > bx.s.high)
        return 2;
    if ((USItype) ax.s.low < (USItype) bx.s.low)
        return 0;
    else if ((USItype) ax.s.low > (USItype) bx.s.low)
        return 2;
    return 1;
}
