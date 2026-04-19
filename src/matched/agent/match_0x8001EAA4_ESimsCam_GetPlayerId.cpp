// 0x8001EAA4 (8B) ESimsCam::GetPlayerId(void)
// Getter for field at offset 0x4.

class ESimsCam {
public:
    char pad_000[0x4];
    int m_field_4;
    int GetPlayerId(void);
};

int ESimsCam::GetPlayerId(void) {
    return m_field_4;
}
