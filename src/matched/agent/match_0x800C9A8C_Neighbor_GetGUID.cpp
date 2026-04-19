// 0x800C9A8C (8B) Neighbor::GetGUID(void)
// Getter for field at offset 0x8.

class Neighbor {
public:
    char pad_000[0x8];
    int m_field_8;
    int GetGUID(void);
};

int Neighbor::GetGUID(void) {
    return m_field_8;
}
