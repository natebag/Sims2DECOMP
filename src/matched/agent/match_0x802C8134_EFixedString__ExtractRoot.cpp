// EFixedString::ExtractRoot(EFixedString&) const - 0x802C8134 (184B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    int FindReverse(char c) const;
    void Left(EFixedString& out, int count) const;
    void Mid(EFixedString& out, int start, int count) const;
    void MakeCopy(char* s);
    void ExtractRoot(EFixedString& out) const;
};

void EFixedString::ExtractRoot(EFixedString& out) const {
    out.MakeCopy(m_pBuffer);
    int dot_pos = out.FindReverse('.');
    if (dot_pos != -1) {
        out.Left(out, dot_pos);
    }
    int backslash_pos = out.FindReverse('\\');
    int colon_pos = out.FindReverse(':');
    if (backslash_pos != -1) {
        out.Mid(out, backslash_pos + 1, -1);
        return;
    }
    if (colon_pos != -1) {
        out.Mid(out, colon_pos + 1, -1);
    }
}
