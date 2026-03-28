class HUDTarget {
public:
    char _pad[0x190];
    int m_playerNum;
};

class SaveGameTarget {
public:
    char _pad[0x118];
    HUDTarget* m_hudTarget;

    int GetPlayerNum(void);
};

int SaveGameTarget::GetPlayerNum(void) {
    return m_hudTarget->m_playerNum;
}
