// 0x8009C1B8 operator==(BString&, char*) (44B)
// No-swap thunk + mode=0 arg + !result idiom
struct BString;

extern int BString__SearchStr(BString& s, char* c, int mode);

int op_eq_BString_charptr(BString& s, char* c) {
    return BString__SearchStr(s, c, 0) == 0;
}
