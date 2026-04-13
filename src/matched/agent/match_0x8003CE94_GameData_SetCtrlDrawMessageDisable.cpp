// FLAGS: -fno-elide-constructors
/* GameData::SetCtrlDrawMessageDisable(GameData::eCtrlDisableBits) at 0x8003CE94 (24B) */

struct GameData {
    char pad[0x124];
    int m_ctrlDisableBits;

    void SetCtrlDrawMessageDisable(int bits);
};

void GameData::SetCtrlDrawMessageDisable(int bits) {
    m_ctrlDisableBits |= (1 << bits);
}
