// EFixedString::Mid(EFixedString&, int, int) const - 0x802C7874 (84B)

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    void MakeCopy(char* s);
    void Left(EFixedString& out, int count) const;
    void Mid(EFixedString& out, int start, int count) const;
};

void EFixedString::Mid(EFixedString& out, int start, int count) const {
    out.MakeCopy(m_pBuffer + start);
    if (count != -1) {
        out.Left(out, count);
    }
}
