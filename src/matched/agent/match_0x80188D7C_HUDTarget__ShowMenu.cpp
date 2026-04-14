// 0x80188D7C HUDTarget::ShowMenu(int) (64B)
struct MenuEntry { char data[180]; };

struct HUDTarget {
    char pad[1856];
    MenuEntry m_menus[1];
};

extern void HUDTarget__PreMenu(HUDTarget* self);
extern void HUDMenu__ShowImpl(MenuEntry* m);

void HUDTarget__ShowMenu(HUDTarget* self, int idx) {
    HUDTarget__PreMenu(self);
    HUDMenu__ShowImpl(&self->m_menus[idx]);
}
