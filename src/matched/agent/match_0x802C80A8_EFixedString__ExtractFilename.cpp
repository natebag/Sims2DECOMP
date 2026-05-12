// EFixedString::ExtractFilename(EFixedString&) const - 0x802C80A8 (140B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    int FindReverse(char c) const;
    void Mid(EFixedString& out, int start, int count) const;
    void MakeCopy(char* s);
    void ExtractFilename(EFixedString& out) const;
};

void EFixedString::ExtractFilename(EFixedString& out) const {
    int slash_pos = FindReverse('\\');
    int colon_pos = FindReverse(':');
    if (slash_pos != -1) {
        Mid(out, slash_pos + 1, -1);
        return;
    }
    if (colon_pos != -1) {
        Mid(out, colon_pos + 1, -1);
        return;
    }
    out.MakeCopy(m_pBuffer);
}
