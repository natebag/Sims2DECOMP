// 0x801E45B8 (84 bytes)
// WAFTarget::OnBottomBarTweenComplete(void)

class WAFTarget { public: void OnBottomBarTweenComplete(void); };

__attribute__((naked))
void WAFTarget::OnBottomBarTweenComplete(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C691B78\n.long 0xC1A9027C\n.long 0xC0090274\n.long 0xFC0D0000\n.long 0x4082000C\n.long 0x38000001\n.long 0x90090268\n.long 0xC009027C\n.long 0x38000000\n.long 0x90090264\n.long 0x7D234B78\n.long 0xD0090278\n.long 0x48000265\n.long 0x38600001\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
