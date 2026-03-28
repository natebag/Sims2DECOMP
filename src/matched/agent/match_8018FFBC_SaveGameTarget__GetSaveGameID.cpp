class HUDTarget {
public:
    int GetSaveGameID(void);
};

class SaveGameTarget {
public:
    char _pad[0x118];
    HUDTarget* m_hudTarget;

    int GetSaveGameID(void);
};

int SaveGameTarget::GetSaveGameID(void) {
    return m_hudTarget->GetSaveGameID();
}
