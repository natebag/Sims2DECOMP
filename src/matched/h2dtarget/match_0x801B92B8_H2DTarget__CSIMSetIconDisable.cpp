/* H2DTarget::CSIMSetIconDisable(int, bool) at 0x801B92B8 (48B) */

struct CSMTarget_SID {
    void SetIconDisable(bool b);
};

struct H2DTarget_SID {
    char m_pad[144];
    CSMTarget_SID* m_icons[1];
    void CSIMSetIconDisable(int idx, bool b);
};

void H2DTarget_SID::CSIMSetIconDisable(int idx, bool b) {
    m_icons[idx]->SetIconDisable(b);
}
