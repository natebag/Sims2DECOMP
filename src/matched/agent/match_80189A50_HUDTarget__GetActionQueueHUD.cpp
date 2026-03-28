class ActionQueueHUD {
public:
    char _data[0x31C];
};

class HUDTarget {
public:
    char _pad[0x108];
    ActionQueueHUD m_actionQueueHUD[4];

    ActionQueueHUD* GetActionQueueHUD(int index);
};

ActionQueueHUD* HUDTarget::GetActionQueueHUD(int index) {
    return &m_actionQueueHUD[index];
}
