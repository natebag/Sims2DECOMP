// EFixedString::ExtractDirectory(EFixedString&) const - 0x802C81EC (144B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    int FindReverse(char c) const;
    void Left(EFixedString& out, int count) const;
    void MakeCopy(char* s);
    void ExtractDirectory(EFixedString& out) const;
};

void EFixedString::ExtractDirectory(EFixedString& out) const {
    int slash_pos = FindReverse('\\');
    int colon_pos;
    if (slash_pos != -1) goto slash_found;
    colon_pos = FindReverse(':');
    if (colon_pos != -1) goto colon_found;
    out.MakeCopy("");
    return;
colon_found:
    Left(out, colon_pos + 1);
    return;
slash_found:
    Left(out, slash_pos + 1);
}
