class HUDTarget {
public:
    int GetDevice(void);
};

class SaveGameTarget {
public:
    char _pad[0x118];
    HUDTarget* m_hudTarget;

    int GetDevice(void);
};

int SaveGameTarget::GetDevice(void) {
    return m_hudTarget->GetDevice();
}
