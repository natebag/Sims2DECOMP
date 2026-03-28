// 0x80145448 (12 bytes)
// SpriteSlot::GetIsSkillMeter(void) const
// lwz r3, 72(r3); rlwinm r3, r3, 28, 31, 31; blr
class SpriteSlot {
public:
    char m_pad[72];
    int m_flags;
    int GetIsSkillMeter() const;
};

int SpriteSlot::GetIsSkillMeter() const {
    return (m_flags >> 4) & 1;
}
