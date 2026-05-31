// 0x80189A78 HUDTarget::HUDHideComplete(void) (16 B)

struct HUDTarget {
    char pad_0000[0xe8];
    unsigned char m_hideState;

    bool HUDHideComplete();
};

bool HUDTarget::HUDHideComplete() {
    return m_hideState == 0;
}
