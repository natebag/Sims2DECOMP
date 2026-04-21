// 0x8009C304 operator<(BString &, BString &) (44B)
struct BString;
extern int BString__compare2(BString* self, BString* other, int len, int maxlen);

int operator_lt_BString_BString(BString* self, BString* other) {
    return BString__compare2(self, other, 0, -1) < 0;
}
