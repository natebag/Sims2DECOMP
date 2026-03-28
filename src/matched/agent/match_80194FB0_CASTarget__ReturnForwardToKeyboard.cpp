// 0x80194FB0 (80 bytes)
// CASTarget::ReturnForwardToKeyboard(void)

class CASTarget { public: void ReturnForwardToKeyboard(void); };

__attribute__((naked))
void CASTarget::ReturnForwardToKeyboard(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x3C60803F\n.long 0x3863C0C0\n.long 0x4BFE4B05\n.long 0x7C631B79\n.long 0x41820010\n.long 0x2C030001\n.long 0x41820014\n.long 0x48000018\n.long 0x38600002\n.long 0x48029F61\n.long 0x4800000C\n.long 0x38600004\n.long 0x48029F55\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
