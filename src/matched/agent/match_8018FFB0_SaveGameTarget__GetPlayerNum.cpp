class SomeHUDData {
public:
    char _pad[0x190];
    int m_playerNum;
};

class SaveGameTarget {
public:
    char _pad[0x118];
    SomeHUDData* m_hudData;

    int GetPlayerNum(void);
};

int SaveGameTarget::GetPlayerNum(void) {
    return m_hudData->m_playerNum;
}
