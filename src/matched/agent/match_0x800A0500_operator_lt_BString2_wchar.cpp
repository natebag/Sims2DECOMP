// operator<(BString2 &, unsigned wchar_t *)
// Address: 0x800A0500 | Size: 40 bytes

typedef unsigned short wchar_t;

struct BString2;

extern "C" int _ZNK8BString27compareEPtj(const BString2* self, const wchar_t* str, unsigned int start);

bool operator_lt_BString2_wchar(BString2* self, const wchar_t* other) {
    return _ZNK8BString27compareEPtj(self, other, 0) < 0;
}
