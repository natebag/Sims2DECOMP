/* GameData::ClearCtrlDrawMessageDisable(GameData::eCtrlDisableBits) at 0x8003CEAC (24B) */

struct GameData {
    char pad[0x124];
    int m_ctrlDisableBits;

    void ClearCtrlDrawMessageDisable(int bits);
};

void GameData::ClearCtrlDrawMessageDisable(int bits) {
    m_ctrlDisableBits &= ~(1 << bits);
}
