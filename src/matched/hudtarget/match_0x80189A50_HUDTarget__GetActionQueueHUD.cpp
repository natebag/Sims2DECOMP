// HUDTarget::GetActionQueueHUD(int) @ 0x80189A50 (16B)

struct AQH_Item { char data[796]; };

struct HudTgt {
    char _pad[264];
    AQH_Item m_huds[];
    AQH_Item* GetActionQueueHUD(int idx);
};

AQH_Item* HudTgt::GetActionQueueHUD(int idx) {
    return &m_huds[idx];
}
