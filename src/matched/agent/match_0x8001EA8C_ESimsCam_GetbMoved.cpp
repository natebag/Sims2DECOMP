// 0x8001EA8C (8B) ESimsCam::GetbMoved(void) const
// Getter for field at offset 0x8.

class ESimsCam {
public:
    char pad_000[0x8];
    int m_field_8;
    int GetbMoved(void) const;
};

int ESimsCam::GetbMoved(void) const {
    return m_field_8;
}
