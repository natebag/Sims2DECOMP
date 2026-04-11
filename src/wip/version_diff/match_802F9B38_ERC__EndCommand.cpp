class ERC {
public:
    char m_pad[20];
    int m_endFlag;
    unsigned char m_openCount;
    void EndCommand();
};
void ERC::EndCommand() {
    m_endFlag = 1;
    m_openCount--;
}
