// EFixedString::ExtractExtension(EFixedString&) const - 0x802C827C (120B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    int FindReverse(char c) const;
    void Mid(EFixedString& out, int start, int count) const;
    void ExtractExtension(EFixedString& out) const;
};

void EFixedString::ExtractExtension(EFixedString& out) const {
    int dot_pos = FindReverse('.');
    int slash_pos = FindReverse('\\');
    if (dot_pos == -1 || dot_pos < slash_pos) {
        out.m_pBuffer[0] = '\0';
    } else {
        Mid(out, dot_pos + 1, -1);
    }
}
