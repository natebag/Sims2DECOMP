class HUDTarget {
public:
    int GetSaveGameID(void);
};

class LoadGameTarget {
public:
    char _pad[0x118];
    HUDTarget* m_hudTarget;

    int GetSaveGameID(void);
};

int LoadGameTarget::GetSaveGameID(void) {
    return m_hudTarget->GetSaveGameID();
}
