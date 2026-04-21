// 0x8009C578 operator<=(char, BString&) (48B)
// Arg-swap thunk + xori: !(s < c) = (c <= s)
struct BString;

extern int op_lt_BString_char(BString& s, char c);

int op_le_char_BString(char c, BString& s) {
    return op_lt_BString_char(s, c) ^ 1;
}
