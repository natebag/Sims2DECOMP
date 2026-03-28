class HUDTarget {
public:
    int GetDevice(void);
};

class LoadGameTarget {
public:
    char _pad[0x118];
    HUDTarget* m_hudTarget;

    int GetDevice(void);
};

int LoadGameTarget::GetDevice(void) {
    return m_hudTarget->GetDevice();
}
