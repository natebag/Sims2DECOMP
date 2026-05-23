// PRAGMA_STUB: HUDTarget::OnPlayerHUDShow(int)
// 0x80187F24 HUDTarget::OnPlayerHUDShow(int) (48B)
struct HUDTarget {
    char pad[233];
    unsigned char m_states[1];
};

extern void HUDTarget__UpdateHUDState(HUDTarget* self, int player, int flag);

void HUDTarget__OnPlayerHUDShow(HUDTarget* self, int player) {
    self->m_states[player] = 2;
    HUDTarget__UpdateHUDState(self, player, 1);
}
