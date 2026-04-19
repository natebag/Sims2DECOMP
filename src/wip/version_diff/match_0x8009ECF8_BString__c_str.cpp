/* BString::c_str(void) const at 0x8009ECF8 (48B) */

extern char gBStringEmpty[];

struct BString_CS {
    char* data() const;
    char* c_str() const;
};

char* BString_CS::c_str() const {
    char* p = data();
    if (!p)
        p = gBStringEmpty;
    return p;
}
