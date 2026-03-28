// 0x80091348 (112 bytes)
// LoadingScreenFadeOutState::FaderUpdate(float)

class LoadingScreenFadeOutState { public: void FaderUpdate(float); };

__attribute__((naked))
void LoadingScreenFadeOutState::FaderUpdate(float) {
    asm volatile(".long 0x81230008\n.long 0x396900A8\n.long 0x800B000C\n.long 0x70090010\n.long 0x4D820020\n.long 0x3D20803E\n.long 0xC00B0008\n.long 0xC1A98110\n.long 0xFC006800\n.long 0x4D820020\n.long 0xEC000828\n.long 0xFC006800\n.long 0xD00B0008\n.long 0x4C620382\n.long 0x4C830020\n.long 0xD1AB0008\n.long 0x70090001\n.long 0x41820014\n.long 0x5400003C\n.long 0x60000004\n.long 0x900B000C\n.long 0x4E800020\n.long 0x70090002\n.long 0x4D820020\n.long 0x540007FA\n.long 0x60000008\n.long 0x900B000C\n.long 0x4E800020");
}
