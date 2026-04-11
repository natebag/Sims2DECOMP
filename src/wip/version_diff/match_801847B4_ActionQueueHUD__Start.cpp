class HUDTarget;

class ActionQueueHUD {
public:
    HUDTarget* m_hudTarget;
    char _pad[0x314];
    unsigned char m_started;

    void Start(HUDTarget* target);
};

void ActionQueueHUD::Start(HUDTarget* target) {
    m_hudTarget = target;
    m_started = 1;
}
