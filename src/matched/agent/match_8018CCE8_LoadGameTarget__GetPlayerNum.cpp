class SomeHUDData {
public:
    char _pad[0x190];
    int m_playerNum;
};

class LoadGameTarget {
public:
    char _pad[0x118];
    SomeHUDData* m_hudData;

    int GetPlayerNum(void);
};

int LoadGameTarget::GetPlayerNum(void) {
    return m_hudData->m_playerNum;
}
