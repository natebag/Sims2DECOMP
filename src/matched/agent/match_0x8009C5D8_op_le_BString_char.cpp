// 0x8009C5D8 operator<=(BString&, char) (48B)
// Arg-swap thunk + xori
struct BString;

extern int op_lt_char_BString(char c, BString& b);

int op_le_BString_char(BString& b, char c) {
    return op_lt_char_BString(c, b) ^ 1;
}
