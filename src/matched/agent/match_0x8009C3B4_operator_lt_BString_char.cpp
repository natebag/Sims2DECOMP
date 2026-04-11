// operator<(BString &, char *)
// Address: 0x8009C3B4 | Size: 40 bytes

struct BString;

extern "C" int _ZNK7BString7compareEPcj(const BString* self, const char* str, unsigned int start);

bool operator_lt_BString_char(BString* self, const char* other) {
    return _ZNK7BString7compareEPcj(self, other, 0) < 0;
}
