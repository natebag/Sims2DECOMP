class EMemoryWriteStream {
public:
    char m_pad[28];
    int m_nPos;
    int GetPos() const;
};
int EMemoryWriteStream::GetPos() const { return m_nPos; }
