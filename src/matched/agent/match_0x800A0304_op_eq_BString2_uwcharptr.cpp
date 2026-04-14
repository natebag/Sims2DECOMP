// 0x800A0304 operator==(BString2&, unsigned wchar_t*) (44B)
// No-swap + mode=0 + !result idiom
struct BString2;

extern int BString2__SearchUWStr(BString2& b, unsigned short* s, int mode);

int op_eq_BString2_uwcharptr(BString2& b, unsigned short* s) {
    return BString2__SearchUWStr(b, s, 0) == 0;
}
