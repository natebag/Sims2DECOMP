// 0x800A06F4 operator<=(BString2&, unsigned wchar_t*) (48B)
// Arg-swap thunk + xori
struct BString2;

extern int op_lt_uwcharptr_BString2(unsigned short* s, BString2& b);

int op_le_BString2_uwcharptr(BString2& b, unsigned short* s) {
    return op_lt_uwcharptr_BString2(s, b) ^ 1;
}
