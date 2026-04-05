/* FlashPiMenu::FlashPiMenu(void) at 0x8003AFB8 (20B) */

extern int vtbl_FlashPiMenu[];

struct FlashPiMenu {
    char pad[0xC];
    int* m_vptr;

    FlashPiMenu(void);
};

FlashPiMenu::FlashPiMenu(void) {
    m_vptr = vtbl_FlashPiMenu;
}
