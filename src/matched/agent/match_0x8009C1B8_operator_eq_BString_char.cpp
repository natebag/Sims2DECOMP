struct BString;
extern int BString__compare(BString* self, char* str, int len);

int operator_eq_BString_char(BString* self, char* str) {
    return BString__compare(self, str, 0) == 0;
}
