// 0x80188D3C HUDTarget::CompleteMenu(int) (64B)
struct MenuEntry { char data[180]; };

struct HUDTarget {
    char pad[1856];
    MenuEntry m_menus[1];
};

extern void HUDTarget__PreMenu(HUDTarget* self);
extern void HUDMenu__CompleteImpl(MenuEntry* m);

void HUDTarget__CompleteMenu(HUDTarget* self, int idx) {
    HUDTarget__PreMenu(self);
    HUDMenu__CompleteImpl(&self->m_menus[idx]);
}
