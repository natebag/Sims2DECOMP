// 0x801833FC ActionMenu::Start(HUDTarget*, int) (20B)
// FLAGS: -fno-schedule-insns
class HUDTarget;

class ActionMenu {
public:
    HUDTarget* m_target;
    char _pad1[0x05];
    unsigned char m_active;
    char _pad2[0x9E];
    int m_playerIndex;

    void Start(HUDTarget* target, int playerIndex);
};

void ActionMenu::Start(HUDTarget* target, int playerIndex) {
    m_active = 1;
    m_playerIndex = playerIndex;
    m_target = target;
}
