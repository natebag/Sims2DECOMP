// operator<=(char *, BString &)
// Address: 0x8009C548 | Size: 48 bytes
// FLAGS: -fno-elide-constructors

class BString;

// Internal function at 0x8009C3B4 - probably operator<(BString&, char*)
extern int operator_lt_BString_char_ptr(BString& a, char* b);

int operator<=(char* a, BString& b) {
    // a <= b is equivalent to !(b < a)
    // But here it seems to call operator<(b, a) and process result
    int result = operator_lt_BString_char_ptr(b, a);
    // ori r3, r3, 1 - set low bit
    return result | 1;
}
