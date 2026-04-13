// 0x801847B4 ActionQueueHUD::Start(HUDTarget*) (16B)
// FLAGS: -fno-schedule-insns
class HUDTarget;

class ActionQueueHUD {
public:
    HUDTarget* m_hudTarget;
    char _pad[0x314];
    unsigned char m_started;

    void Start(HUDTarget* target);
};

void ActionQueueHUD::Start(HUDTarget* target) {
    m_started = 1;
    m_hudTarget = target;
}
