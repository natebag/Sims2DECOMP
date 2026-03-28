// 0x801FC438 (96 bytes)
// OPTTarget::GetScreenYGlobal(float)

class OPTTarget { public: void GetScreenYGlobal(float); };

__attribute__((naked))
void OPTTarget::GetScreenYGlobal(float) {
    asm volatile(".long 0x9421FFF0\n.long 0x3D208040\n.long 0xC169AEF8\n.long 0xFC015800\n.long 0x4180001C\n.long 0x3D208040\n.long 0xEC015828\n.long 0xC189AF04\n.long 0xEC00002A\n.long 0xEC005B3A\n.long 0x48000020\n.long 0x3D208040\n.long 0x3D608040\n.long 0xC009AEFC\n.long 0xED81082A\n.long 0xC16BAF00\n.long 0xEC006028\n.long 0xEC0002F2\n.long 0xFDA0001E\n.long 0xD9A10008\n.long 0x8061000C\n.long 0x7C630774\n.long 0x38210010\n.long 0x4E800020");
}
