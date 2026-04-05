/* BString::find_first_of(char *, unsigned int) const - 0x8009F338 (88 bytes) */

struct BString {
    int _find_first_of_internal(const char *str, unsigned int startIdx, unsigned int len) const;
};

extern unsigned int strlen(const char *str);

int BString__find_first_of_char_ptr_unsigned_int_const(const BString *thisPtr, const char *str, unsigned int startIdx) {
    unsigned int len;
    
    if (str != 0) {
        len = strlen(str);
    } else {
        len = 0;
    }
    
    return thisPtr->_find_first_of_internal(str, startIdx, len);
}
