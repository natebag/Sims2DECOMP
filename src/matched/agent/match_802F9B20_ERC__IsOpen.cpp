class ERC {
public:
    char m_pad[24];
    unsigned char m_openCount;
    bool IsOpen() const;
};
bool ERC::IsOpen() const {
    return m_openCount != 0;
}
