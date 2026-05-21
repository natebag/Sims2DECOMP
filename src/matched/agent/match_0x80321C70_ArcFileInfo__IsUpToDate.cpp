// 0x80321C70 ArcFileInfo::IsUpToDate(void) (40B)
// Checks field+4 then field+0; both must be non-zero to return field+16.
// Tail-merged zero return via goto.

struct ArcFileInfo {
    int m_f0;
    int m_f4;
    char pad[8];
    int m_f10;
    int IsUpToDate();
};

int ArcFileInfo::IsUpToDate() {
    if (m_f4 == 0) goto return_zero;
    if (m_f0 == 0) goto return_zero;
    return m_f10;
return_zero:
    return 0;
}
