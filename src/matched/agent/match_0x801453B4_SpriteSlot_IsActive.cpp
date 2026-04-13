// 0x801453B4 SpriteSlot::IsActive (24b)
struct SpriteSlot {
    char pad[0x10];
    int m_active;
    int IsActive() const;
};

int SpriteSlot::IsActive() const {
    int result = 1;
    if (m_active != 0) return result;
    result = 0;
    return result;
}
