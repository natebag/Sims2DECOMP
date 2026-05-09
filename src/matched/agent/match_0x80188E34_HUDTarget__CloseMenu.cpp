// PRAGMA_STUB: HUDTarget::CloseMenu(int)
// 0x80188E34 HUDTarget::CloseMenu(int) (44B)
struct MenuEntry { char data[180]; };

struct HUDTarget {
    char pad[1856];
    MenuEntry m_menus[1];
};

extern void HUDMenu__CloseImpl(MenuEntry* m);

void HUDTarget__CloseMenu(HUDTarget* self, int idx) {
    HUDMenu__CloseImpl(&self->m_menus[idx]);
}
