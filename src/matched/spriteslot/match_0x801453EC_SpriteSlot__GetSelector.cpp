/* SpriteSlot::GetSelector(void) const - 0x801453EC (28 bytes) */

class SpriteSlot {
public:
    char pad0[24];
    int m_type;       // +24
    char pad1[12];
    void* m_selector; // +40

    void* GetSelector(void) const;
};

void* SpriteSlot::GetSelector(void) const {
    if (m_type == -1) return m_selector;
    return 0;
}
