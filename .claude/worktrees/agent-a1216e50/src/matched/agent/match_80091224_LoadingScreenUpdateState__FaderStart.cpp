// 0x80091224 (64 bytes)
// LoadingScreenUpdateState::FaderStart(float)

class LoadingScreenUpdateState { public: void FaderStart(float); };

__attribute__((naked))
void LoadingScreenUpdateState::FaderStart(float) {
    asm volatile(".long 0x81630008\n.long 0x38000010\n.long 0x3D40803E\n.long 0x3900FFF2\n.long 0x392B00A8\n.long 0x9009000C\n.long 0xD0290008\n.long 0xD02B00A8\n.long 0xC00A80F8\n.long 0x8009000C\n.long 0xEC000824\n.long 0x7C004038\n.long 0x60000002\n.long 0x9009000C\n.long 0xD0090004\n.long 0x4E800020");
}
