// 0x8009F8FC (104B) BString::compare(char*, unsigned int) const

extern "C" unsigned int strlen(const char*);

class BString {
public:
    int length() const;
    int compare_str(unsigned int, char*, unsigned int, unsigned int) const;
    int compare(char* s, unsigned int len) const;
};

int BString::compare(char* s, unsigned int len) const {
    int my_len = length();
    unsigned int diff = (unsigned int)my_len - len;
    unsigned int slen;
    if (s != 0) {
        slen = strlen(s);
    } else {
        slen = 0;
    }
    return compare_str(len, s, diff, slen);
}
