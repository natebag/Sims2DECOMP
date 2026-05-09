// ActionQueueHUD::Start(HUDTarget *) @ 0x801847B4 (16B)

struct AQH_Sta {
    void* m_hudTarget;
    char _pad[788];
    unsigned char m_active;
    void Start(void* target);
};

void AQH_Sta::Start(void* target) {
    m_hudTarget = target;
    m_active = 1;
}
