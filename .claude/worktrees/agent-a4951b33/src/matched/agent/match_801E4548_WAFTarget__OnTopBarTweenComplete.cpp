// 0x801E4548 (112 bytes)
// WAFTarget::OnTopBarTweenComplete(void)

class WAFTarget { public: void OnTopBarTweenComplete(void); };

__attribute__((naked))
void WAFTarget::OnTopBarTweenComplete(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0xC1BF027C\n.long 0xC01F0274\n.long 0xFC0D0000\n.long 0x4082000C\n.long 0x38000001\n.long 0x901F0268\n.long 0xC01F027C\n.long 0x38000000\n.long 0x901F0264\n.long 0x7FE3FB78\n.long 0xD01F0278\n.long 0x480002D1\n.long 0x801F026C\n.long 0x2C000000\n.long 0x4082000C\n.long 0x7FE3FB78\n.long 0x48000471\n.long 0x38600001\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
