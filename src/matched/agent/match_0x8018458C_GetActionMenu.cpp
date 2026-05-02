// GetActionMenu(unsigned int) - 0x8018458C (56 bytes)
//
// Tech #73 application — classic 3-path predicate (inline false, tail false,
// success-fallthrough). Same pattern as INGTarget::get_current_inginfo.
//
// FLAGS: -msdata=eabi -G 8

extern char g_actionMenuPtrStorage[16];

char* GetActionMenu(unsigned int idx) {
    if (idx > 1) return 0;
    char* g = *(char**)g_actionMenuPtrStorage;
    if (g == 0) return 0;
    return g + (idx * 180 + 1856);
}
