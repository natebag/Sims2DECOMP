class EMemoryReadStream {
public:
    char m_pad[32];
    int m_nPos;
    int GetPos() const;
};
int EMemoryReadStream::GetPos() const { return m_nPos; }
