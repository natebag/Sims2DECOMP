class ActionQueueHUD {
};

class HUDTarget {
public:
    char _pad[0x108];
    char m_actionQueues[4 * 0x31C];

    ActionQueueHUD* GetActionQueueHUD(int player);
};

ActionQueueHUD* HUDTarget::GetActionQueueHUD(int player) {
    return (ActionQueueHUD*)&m_actionQueues[player * 0x31C];
}
