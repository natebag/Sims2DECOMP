// 0x80189A88 HUDTarget::HideInProgress(void) (20 B)

struct HUDTarget {
    char pad_0000[0xe8];
    unsigned char m_hideState;

    bool HideInProgress();
};

bool HUDTarget::HideInProgress() {
    return m_hideState == 1;
}
