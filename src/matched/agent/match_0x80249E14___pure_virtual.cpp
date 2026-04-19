// 0x80249E14 (32B) __pure_virtual
// Thunk to __terminate

extern void __terminate(void);

void __pure_virtual(void) {
    __terminate();
}
