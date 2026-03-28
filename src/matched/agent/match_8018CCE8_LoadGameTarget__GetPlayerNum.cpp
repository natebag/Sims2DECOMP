class HUDTarget {
public:
    char _pad[0x190];
    int m_playerNum;
};

class LoadGameTarget {
public:
    char _pad[0x118];
    HUDTarget* m_hudTarget;

    int GetPlayerNum(void);
};

int LoadGameTarget::GetPlayerNum(void) {
    return m_hudTarget->m_playerNum;
}
