// 0x8018A6BC (76 bytes)
// LoadGameTarget::ZeroInputCallback(void)

class LoadGameTarget { public: void ZeroInputCallback(void); };

__attribute__((naked))
void LoadGameTarget::ZeroInputCallback(void) {
    asm volatile(".long 0x8003012C\n.long 0x2C000004\n.long 0x41820038\n.long 0x41810010\n.long 0x2C000000\n.long 0x4182001C\n.long 0x4E800020\n.long 0x2C000013\n.long 0x41820020\n.long 0x2C000018\n.long 0x41820018\n.long 0x4E800020\n.long 0x38000001\n.long 0x90030130\n.long 0x9003012C\n.long 0x4E800020\n.long 0x38000001\n.long 0x90030130\n.long 0x4E800020");
}
