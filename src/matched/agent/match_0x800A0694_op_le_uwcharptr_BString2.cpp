// 0x800A0694 operator<=(unsigned wchar_t*, BString2&) (40B)
// Arg-swap thunk + xori
struct BString2;

extern int op_lt_BString2_uwcharptr(BString2& b, unsigned short* s);

int op_le_uwcharptr_BString2(unsigned short* s, BString2& b) {
    return op_lt_BString2_uwcharptr(b, s) ^ 1;
}
