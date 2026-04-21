// 0x8009C17C operator==(char, BString&) (60B)
// Arg-swap + extra args, then !result idiom
struct BString;

extern int BString__SearchChar(BString& s, char c, int a, int b);

int op_eq_char_BString(char c, BString& s) {
    return BString__SearchChar(s, c, 0, 1) == 0;
}
