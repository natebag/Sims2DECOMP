// 0x800BA668 (8B) cGZSnd::GetVolume(void)
// Getter for field at offset 0x20.

class cGZSnd {
public:
    char pad_000[0x20];
    int m_field_20;
    int GetVolume(void);
};

int cGZSnd::GetVolume(void) {
    return m_field_20;
}
