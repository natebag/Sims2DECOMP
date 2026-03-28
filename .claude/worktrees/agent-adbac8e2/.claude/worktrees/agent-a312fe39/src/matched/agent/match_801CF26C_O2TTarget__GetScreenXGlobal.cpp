// 0x801CF26C (96 bytes)
// O2TTarget::GetScreenXGlobal(float)

class O2TTarget { public: void GetScreenXGlobal(float); };

__attribute__((naked))
void O2TTarget::GetScreenXGlobal(float) {
    asm volatile(".long 0x9421FFF0\n.long 0x3D20803F\n.long 0xC1693EC0\n.long 0xFC015800\n.long 0x4180001C\n.long 0x3D20803F\n.long 0xEC015828\n.long 0xC1893ECC\n.long 0xEC00002A\n.long 0xEC005B3A\n.long 0x48000020\n.long 0x3D20803F\n.long 0x3D60803F\n.long 0xC0093EC4\n.long 0xED81082A\n.long 0xC16B3EC8\n.long 0xEC006028\n.long 0xEC0002F2\n.long 0xFDA0001E\n.long 0xD9A10008\n.long 0x8061000C\n.long 0x7C630774\n.long 0x38210010\n.long 0x4E800020");
}
