// 0x80187F54 HUDTarget::OnPlayerHUDHide(int) (44B)
struct HUDTarget {
    char pad[233];
    unsigned char m_states[1];
};

extern void HUDTarget__HidePlayerHUD(HUDTarget* self, int player);

void HUDTarget__OnPlayerHUDHide(HUDTarget* self, int player) {
    self->m_states[player] = 0;
    HUDTarget__HidePlayerHUD(self, player);
}
