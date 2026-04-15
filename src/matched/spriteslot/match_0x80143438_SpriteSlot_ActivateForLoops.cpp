// 0x80143438 SpriteSlot::ActivateForLoops(int) (44B)

struct SpriteSlot {
    char pad[44];
    int m_mult;   // +44
    void ActivateForLoops(int n);
    void Activate(int bytes);
};

void SpriteSlot::ActivateForLoops(int n) {
    int m = m_mult * 12;
    Activate(m * n);
}
