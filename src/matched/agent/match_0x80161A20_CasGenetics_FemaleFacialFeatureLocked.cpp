// 0x80161A20 (76B)
// CasGenetics::FemaleFacialFeatureLocked(signed char)
// FLAGS: -msdata=eabi -G 8

struct CasGenetics {
    int FemaleFacialFeatureLocked(signed char x);
};

int CasGenetics::FemaleFacialFeatureLocked(signed char x) {
    if ((unsigned int)(x - 6) <= 1) goto yes;
    if (x == 9) goto yes;
    if (x == 10) goto yes;
    if (x == 12) goto yes;
    if (x == 13) goto yes;
    if (x == 14) goto yes;
    if (x != 15) goto no;
yes:
    return 1;
no:
    return 0;
}
