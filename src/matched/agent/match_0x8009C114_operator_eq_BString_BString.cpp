// operator==(BString &, BString &)
// Address: 0x8009C114 | Size: 48 bytes
// FLAGS: -fno-elide-constructors

class BString;

// Internal comparison function at 0x8009F818
// Returns 0 if equal, non-zero otherwise
extern int BString_CompareInternal(BString* a, BString* b, int pos, int len);

int operator==(BString& a, BString& b) {
    int result = BString_CompareInternal(&a, &b, 0, -1);
    return result == 0;
}
