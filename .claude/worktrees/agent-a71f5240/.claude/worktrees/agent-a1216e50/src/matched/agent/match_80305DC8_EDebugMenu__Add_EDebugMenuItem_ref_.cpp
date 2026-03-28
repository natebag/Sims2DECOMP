// 0x80305DC8 (72 bytes)
// EDebugMenu::Add(EDebugMenuItem &)

class EDebugMenu { public: void Add(EDebugMenuItem &); };

__attribute__((naked))
void EDebugMenu::Add(EDebugMenuItem &) {
    asm volatile(".long 0x3943000C\n.long 0x800A0004\n.long 0x90040000\n.long 0x812A0004\n.long 0x2C090000\n.long 0x4182000C\n.long 0x90890004\n.long 0x48000008\n.long 0x9083000C\n.long 0x38000000\n.long 0x39600001\n.long 0x90040004\n.long 0x908A0004\n.long 0x91630008\n.long 0x81230018\n.long 0x39290001\n.long 0x91230018\n.long 0x4E800020");
}
