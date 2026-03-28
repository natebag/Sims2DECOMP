// 0x801FC498 (120 bytes)
// OPTTarget::RememberOptions(void)

class OPTTarget { public: void RememberOptions(void); };

__attribute__((naked))
void OPTTarget::RememberOptions(void) {
    asm volatile(".long 0x3D608047\n.long 0x396B5DCC\n.long 0x812B0148\n.long 0x8809001C\n.long 0x98030084\n.long 0x812B0148\n.long 0x8809001D\n.long 0x98030085\n.long 0x812B0148\n.long 0x8809001F\n.long 0x98030086\n.long 0x812B0148\n.long 0x88090020\n.long 0x98030087\n.long 0x812B0148\n.long 0x80090004\n.long 0x90030088\n.long 0x812B0148\n.long 0x80090000\n.long 0x9003008C\n.long 0x812B0148\n.long 0x80090014\n.long 0x90030090\n.long 0x812B0148\n.long 0x80090018\n.long 0x90030094\n.long 0x812B0148\n.long 0x80090010\n.long 0x90030098\n.long 0x4E800020");
}
