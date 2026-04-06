// operator<=(char *, BString &)
// Address: 0x8009C548 | Size: 48 bytes
// FLAGS: -fno-elide-constructors

class BString;

// Internal function at 0x8009C3B4 - probably operator<(BString&, char*)
extern int operator_lt_BString_char_ptr(BString& a, char* b);

int operator<=(char* a, BString& b) {
    // a <= b is !(b < a)
    // operator< returns 1 for true, 0 for false
    // So we need: !(result) which is result ^ 1 (xori r3, r3, 1)
    int result = operator_lt_BString_char_ptr(b, a);
    return result ^ 1;
}
