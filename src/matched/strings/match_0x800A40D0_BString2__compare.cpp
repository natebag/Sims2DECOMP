// 0x800A40D0 BString2::compare(unsigned wchar_t*, unsigned int, unsigned int) const (96B)
// TRIAGE

namespace basic_string_ref2 {
    extern void throwlength();
}

class BString2 {
public:
    unsigned int length() const;
    int compare_str(unsigned int offset, unsigned short* s, unsigned int diff, unsigned int n) const;
    int compare(unsigned short* s, unsigned int offset, unsigned int n) const;
};

int BString2::compare(unsigned short* s, unsigned int offset, unsigned int n) const {
    if (n == (unsigned int)-1) basic_string_ref2::throwlength();
    return compare_str(offset, s, length() - offset, n);
}
