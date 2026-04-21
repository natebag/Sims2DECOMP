// 0x800A0724 operator<=(BString2&, wchar_t) (48B)
// Arg-swap thunk + xori
struct BString2;

extern int op_lt_wchar_BString2(wchar_t c, BString2& b);

int op_le_BString2_wchar(BString2& b, wchar_t c) {
    return op_lt_wchar_BString2(c, b) ^ 1;
}
