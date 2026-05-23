// 0x8009ECF8 (48B) BString::c_str(void) const
// Call BString::data(), fallback to global empty-string if null.

extern char s_emptyString[];

class BString {
public:
    char* data() const;
    char* c_str() const;
};

char* BString::c_str() const {
    char* p = data();
    if (p != 0) return p;
    return s_emptyString;
}
