// 0x80091264 (120 bytes)
// LoadingScreenUpdateState::FaderGetFadeOpacity(void)

class LoadingScreenUpdateState { public: void FaderGetFadeOpacity(void); };

__attribute__((naked))
void LoadingScreenUpdateState::FaderGetFadeOpacity(void) {
    asm volatile(".long 0x81630008\n.long 0x392B00A8\n.long 0x8009000C\n.long 0x700A0001\n.long 0x4182001C\n.long 0xC00B00A8\n.long 0xC1A90008\n.long 0xC1890004\n.long 0xEC006828\n.long 0xEC200332\n.long 0x4E800020\n.long 0x700B0002\n.long 0x41820014\n.long 0xC1A90004\n.long 0xC0090008\n.long 0xEC200372\n.long 0x4E800020\n.long 0x70090004\n.long 0x41820010\n.long 0x3D20803E\n.long 0xC02980FC\n.long 0x4E800020\n.long 0x700A0008\n.long 0x41820010\n.long 0x3D20803E\n.long 0xC0298100\n.long 0x4E800020\n.long 0x3D20803E\n.long 0xC0298100\n.long 0x4E800020");
}
