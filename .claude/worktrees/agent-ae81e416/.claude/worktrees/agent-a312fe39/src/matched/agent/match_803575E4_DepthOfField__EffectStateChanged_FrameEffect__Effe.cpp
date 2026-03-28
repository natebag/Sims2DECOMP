// 0x803575E4 (68 bytes)
// DepthOfField::EffectStateChanged(FrameEffect::EffectState)

class DepthOfField { public: void EffectStateChanged(FrameEffect::EffectState); };

__attribute__((naked))
void DepthOfField::EffectStateChanged(FrameEffect::EffectState) {
    asm volatile(".long 0x2C040002\n.long 0x4182000C\n.long 0x2C040008\n.long 0x4C820020\n.long 0x80E30028\n.long 0x39630028\n.long 0x800B0008\n.long 0x3923003C\n.long 0x810B0004\n.long 0x814B000C\n.long 0x90E3003C\n.long 0x91090004\n.long 0x90090008\n.long 0x9149000C\n.long 0x800B0010\n.long 0x90090010\n.long 0x4E800020");
}
