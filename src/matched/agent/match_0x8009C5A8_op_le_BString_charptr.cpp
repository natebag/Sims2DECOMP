// 0x8009C5A8 operator<=(BString&, char*) (48B)
// Arg-swap thunk + xori
struct BString;

extern int op_lt_charptr_BString(char* s, BString& b);

int op_le_BString_charptr(BString& b, char* s) {
    return op_lt_charptr_BString(s, b) ^ 1;
}
