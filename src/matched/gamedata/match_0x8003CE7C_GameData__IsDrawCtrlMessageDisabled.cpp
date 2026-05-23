/* GameData::IsDrawCtrlMessageDisabled(void) at 0x8003CE7C (24B) */

struct GameData {
    char pad[0x124];
    int m_ctrlDisableBits;

    int IsDrawCtrlMessageDisabled(void);
};

int GameData::IsDrawCtrlMessageDisabled(void) {
    if (m_ctrlDisableBits != 0) return 1;
    return 0;
}
