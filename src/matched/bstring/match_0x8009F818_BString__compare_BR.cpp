// 0x8009F818 (132B) BString::compare(BString&, unsigned int, unsigned int) const

class BString {
public:
    int length() const;
    char* data() const;
    int compare_str(unsigned int, char*, unsigned int, unsigned int) const;
    int compare(BString& b, unsigned int u1, unsigned int u2) const;
};

int BString::compare(BString& b, unsigned int u1, unsigned int u2) const {
    unsigned int effective;
    if (u2 > (unsigned int)(length() - (int)u1)) {
        effective = (unsigned int)(length() - (int)u1);
    } else {
        effective = u2;
    }
    char* bdata = b.data();
    int blen = b.length();
    return compare_str(u1, bdata, effective, blen);
}
