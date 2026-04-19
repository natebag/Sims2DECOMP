// 0x800BAEBC (8B) cGZMusic::GetVolume(void)
// Getter for field at offset 0x14.

class cGZMusic {
public:
    char pad_000[0x14];
    int m_field_14;
    int GetVolume(void);
};

int cGZMusic::GetVolume(void) {
    return m_field_14;
}
