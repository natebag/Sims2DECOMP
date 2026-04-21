// 0x800A02C8 operator==(wchar_t, BString2&) (60B)
// Swap + (0, 1) args + !result idiom
struct BString2;

extern int BString2__SearchWChar(BString2& b, wchar_t c, int a, int b_);

int op_eq_wchar_BString2(wchar_t c, BString2& b) {
    return BString2__SearchWChar(b, c, 0, 1) == 0;
}
