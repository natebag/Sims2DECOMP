// PRAGMA_STUB: StringBuffer2::appendChar(wchar_t)
// 0x800A718C StringBuffer2::appendChar(wchar_t) (56B)
struct StringBuffer2;

extern void StringBuffer2__append(StringBuffer2* self, unsigned short* s, int n);

void StringBuffer2__appendChar(StringBuffer2* self, wchar_t c) {
    unsigned short buf[2];
    buf[0] = (unsigned short)c;
    buf[1] = 0;
    StringBuffer2__append(self, buf, -1);
}
