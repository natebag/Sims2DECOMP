class EMemoryBufferWriteStream {
public:
    char m_pad[32];
    int m_nPos;
    int GetPos() const;
};
int EMemoryBufferWriteStream::GetPos() const { return m_nPos; }
