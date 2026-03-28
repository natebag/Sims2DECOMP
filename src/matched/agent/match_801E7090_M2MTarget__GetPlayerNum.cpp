class M2MTarget {
public:
    char pad[0x190];
    int m_playerNum;
    int GetPlayerNum(void);
};

int M2MTarget::GetPlayerNum(void) {
    return m_playerNum;
}
