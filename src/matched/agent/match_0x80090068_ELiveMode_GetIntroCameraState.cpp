// 0x80090068 (8B) ELiveMode::GetIntroCameraState(void)
// Getter for field at offset 0xC.

class ELiveMode {
public:
    char pad_000[0xC];
    int m_field_C;
    int GetIntroCameraState(void);
};

int ELiveMode::GetIntroCameraState(void) {
    return m_field_C;
}
