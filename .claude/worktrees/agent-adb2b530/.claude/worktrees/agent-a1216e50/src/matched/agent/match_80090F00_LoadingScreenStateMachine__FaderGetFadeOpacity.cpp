// 0x80090F00 (116 bytes)
// LoadingScreenStateMachine::FaderGetFadeOpacity(void)

class LoadingScreenStateMachine { public: void FaderGetFadeOpacity(void); };

__attribute__((naked))
void LoadingScreenStateMachine::FaderGetFadeOpacity(void) {
    asm volatile(".long 0x392300A8\n.long 0x8009000C\n.long 0x700B0001\n.long 0x4182001C\n.long 0xC00300A8\n.long 0xC1A90008\n.long 0xC1890004\n.long 0xEC006828\n.long 0xEC200332\n.long 0x4E800020\n.long 0x700B0002\n.long 0x41820014\n.long 0xC1A90004\n.long 0xC0090008\n.long 0xEC200372\n.long 0x4E800020\n.long 0x70090004\n.long 0x41820010\n.long 0x3D20803E\n.long 0xC02980C8\n.long 0x4E800020\n.long 0x700B0008\n.long 0x41820010\n.long 0x3D20803E\n.long 0xC02980CC\n.long 0x4E800020\n.long 0x3D20803E\n.long 0xC02980CC\n.long 0x4E800020");
}
