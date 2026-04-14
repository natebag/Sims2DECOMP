// 0x800A06C4 operator<=(wchar_t, BString2&) (40B)
// Arg-swap thunk + xori
struct BString2;

extern int op_lt_BString2_wchar(BString2& b, wchar_t c);

int op_le_wchar_BString2(wchar_t c, BString2& b) {
    return op_lt_BString2_wchar(b, c) ^ 1;
}
