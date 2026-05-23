// 0x80187F80 HUDTarget::OnPlayerHUDHideStart(int) (124B)

class cXObject;

class ActionMenu {
public:
    void CloseMenu();
};

class ActionQueueHUD {
public:
    void RemoveAllActions();
};

class HUDTarget {
public:
    char _pad0[233];
    unsigned char m_hideFlag[1];
    char _pad234[264 - 234];
    ActionQueueHUD m_queues[1];
    char _pad265[1856 - 265];
    ActionMenu m_menus[1];

    int ShouldHUDBeVisible(int idx) const;
    void UpdateActivePlayer(int idx, bool b);
    void OnPlayerHUDHideStart(int idx);
};

void HUDTarget::OnPlayerHUDHideStart(int idx) {
    int menu_off = idx * 180 + 1856;
    ActionMenu* m = (ActionMenu*)((char*)this + menu_off);
    m->CloseMenu();
    if (ShouldHUDBeVisible(idx) == 0) {
        int queue_off = idx * 796 + 264;
        ActionQueueHUD* q = (ActionQueueHUD*)((char*)this + queue_off);
        q->RemoveAllActions();
        UpdateActivePlayer(idx, false);
    }
    unsigned char* hideArr = (unsigned char*)this + 233;
    hideArr[idx] = 1;
}
