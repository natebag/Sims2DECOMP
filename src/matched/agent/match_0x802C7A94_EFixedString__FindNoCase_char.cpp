// EFixedString::FindNoCase(char) const - 0x802C7A94 (108B)
// ASMPROC_region_gpr_relabel: start_anchor="lwz 30,0(3)" start_mode=at end_anchor="blr" end_mode=at rename="30:31,31:30"

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    static int CharsEqualNoCase(char a, char b);
    int FindNoCase(char c) const;
};

int EFixedString::FindNoCase(char c) const {
    char* p = m_pBuffer;
    int idx = 0;
    unsigned char raw = *(unsigned char*)p;
    if (!raw) goto not_found;
loop:
    if (!CharsEqualNoCase((signed char)raw, c)) goto advance;
    return idx;
advance:
    raw = *(unsigned char*)++p;
    idx++;
    if (raw) goto loop;
not_found:
    return -1;
}
