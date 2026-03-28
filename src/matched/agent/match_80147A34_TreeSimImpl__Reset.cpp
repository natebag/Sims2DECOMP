// 0x80147A34 (108 bytes)
// TreeSimImpl::Reset(Behavior *, short)

class TreeSimImpl { public: void Reset(Behavior *, short); };

__attribute__((naked))
void TreeSimImpl::Reset(Behavior *, short) {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0xBFA10014\n.long 0x90010024\n.long 0x7C7F1B78\n.long 0x7CBE2B78\n.long 0x7C9D2378\n.long 0x387F000C\n.long 0x48001671\n.long 0x2C1E0000\n.long 0x41820030\n.long 0x39200000\n.long 0x7FA4EB78\n.long 0x39400000\n.long 0x7FC6F378\n.long 0x91210008\n.long 0x9141000C\n.long 0x7FE3FB78\n.long 0x38A10008\n.long 0x48000021\n.long 0x38000000\n.long 0xB01F0034\n.long 0x80010024\n.long 0x7C0803A6\n.long 0xBBA10014\n.long 0x38210020\n.long 0x4E800020");
}
