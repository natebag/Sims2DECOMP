// 0x800A0290 operator==(unsigned wchar_t*, BString2&) (48B)
// Swap + mode=0 + !result idiom
struct BString2;

extern int BString2__SearchUWStr(BString2& b, unsigned short* s, int mode);

int op_eq_uwcharptr_BString2(unsigned short* s, BString2& b) {
    return BString2__SearchUWStr(b, s, 0) == 0;
}
