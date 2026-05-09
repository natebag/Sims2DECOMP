// cXPersonImpl::AttachToHUD(bool) - 0x80129804 (116B)

struct PlayerSlotTable {
    char pad[188];
    void* slot0;
    void* slot1;
};
extern PlayerSlotTable g_playerSlotTable;

struct ActionQueue_AttachHUD {
    void EnableHUDAccess(int playerIdx);
    void DisableHUDAccess(int playerIdx);
};

struct cXPerson_AttachToHUD {
    char pad0[4];
    void* m_playerSlot;  // offset 4
    char pad1[296];
    ActionQueue_AttachHUD m_queue;  // offset 304

    void AttachToHUD(bool shouldAttach);
};

void cXPerson_AttachToHUD::AttachToHUD(bool shouldAttach) {
    void* slot = m_playerSlot;
    int playerIdx = 0;
    if (slot == g_playerSlotTable.slot0) {
        // player 0
    } else if (slot == g_playerSlotTable.slot1) {
        playerIdx = 1;
    } else {
        shouldAttach = 0;
    }
    if (shouldAttach) {
        m_queue.EnableHUDAccess(playerIdx);
    } else {
        m_queue.DisableHUDAccess(playerIdx);
    }
}
