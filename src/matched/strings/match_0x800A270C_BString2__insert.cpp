// 0x800A270C BString2::insert(unsigned int, unsigned wchar_t*) (92B)
// ASMPROC_swap_adj: a=mr b=mr which=3

extern unsigned int wcslen(unsigned short* s);

class BString2 {
public:
    BString2& insert(unsigned int pos, unsigned short* s);
    BString2& insert_str(unsigned int pos, unsigned short* s, unsigned int n);
};

BString2& BString2::insert(unsigned int pos, unsigned short* s) {
    unsigned int n;
    if (s != 0) {
        n = wcslen(s);
    } else {
        n = 0;
    }
    insert_str(pos, s, n);
    return *this;
}
