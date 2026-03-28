// 0x80129804 (116 bytes)
// cXPersonImpl::AttachToHUD(bool)

class cXPersonImpl { public: void AttachToHUD(bool); };

__attribute__((naked))
void cXPersonImpl::AttachToHUD(bool) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x3D208047\n.long 0x81630004\n.long 0x39295DCC\n.long 0x39400000\n.long 0x800900BC\n.long 0x7C0B0000\n.long 0x4182001C\n.long 0x800900C0\n.long 0x7C0B0000\n.long 0x4082000C\n.long 0x39400001\n.long 0x48000008\n.long 0x38800000\n.long 0x2C040000\n.long 0x41820014\n.long 0x38630130\n.long 0x7D445378\n.long 0x4BFF0F1D\n.long 0x48000010\n.long 0x38630130\n.long 0x7D445378\n.long 0x4BFF0EB1\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
