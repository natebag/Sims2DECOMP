// 0x801A6188 (72 bytes)
// CRDTarget::HidePhoto(void)

class CRDTarget { public: void HidePhoto(void); };

__attribute__((naked))
void CRDTarget::HidePhoto(void) {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0x90010024\n.long 0x38610008\n.long 0x4BFD709D\n.long 0x3C80803F\n.long 0x38610008\n.long 0x3884E154\n.long 0x38A00000\n.long 0x38C00000\n.long 0x4BFD75AD\n.long 0x38610008\n.long 0x38800002\n.long 0x4BFD7099\n.long 0x80010024\n.long 0x7C0803A6\n.long 0x38210020\n.long 0x4E800020");
}
