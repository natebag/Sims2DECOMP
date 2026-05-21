// 0x8009E270 BString::insert(unsigned int, char *) (92B)
// ASMPROC_swap_adj: a=mr b=mr which=3

class BString {
public:
    BString* insert(unsigned int pos, char* str);
    BString* insert_str(unsigned int pos, char* str, unsigned int len);
};

extern "C" int strlen(const char*);

BString* BString::insert(unsigned int pos, char* str) {
    unsigned int len = (str != 0) ? strlen(str) : 0;
    insert_str(pos, str, len);
    return this;
}
