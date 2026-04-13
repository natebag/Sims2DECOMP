// 0x801453B4 SpriteSlot::IsActive (24B)

struct SpriteSlot_IA {
    char pad[0x10];
    int m_active;
    int IsActive() const;
};

int SpriteSlot_IA::IsActive() const {
    int r = 1;
    if (m_active == 0) r = 0;
    return r;
}
