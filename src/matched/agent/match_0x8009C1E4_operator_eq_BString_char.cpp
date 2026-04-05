// operator==(BString &, char)
// Address: 0x8009C1E4 | Size: 48 bytes
// FLAGS: -fno-elide-constructors

class BString;

// Internal comparison function at 0x8009F964
extern int BString_CompareChar(BString* a, char b, int pos, int len);

int operator==(BString& a, char b) {
    int result = BString_CompareChar(&a, b, 0, 1);
    return result == 0;
}
