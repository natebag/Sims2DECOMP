// 0x80039D94 FlashPiMenu::~FlashPiMenu (76B)
// dtor: vtable@+12 + bl CleanUpAllMenus + delete-flag check.

extern int VT_FlashPiMenu[];

struct FlashPiMenu {
    char pad[12];
    int* m_vtable;
    void CleanUpAllMenus();
    ~FlashPiMenu();
};

FlashPiMenu::~FlashPiMenu() {
    m_vtable = VT_FlashPiMenu;
    CleanUpAllMenus();
}
