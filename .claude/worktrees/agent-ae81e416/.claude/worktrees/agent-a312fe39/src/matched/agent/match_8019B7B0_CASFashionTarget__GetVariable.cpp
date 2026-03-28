// 0x8019B7B0 (124 bytes)
// CASFashionTarget::GetVariable(char *)

class CASFashionTarget { public: void GetVariable(char *); };

__attribute__((naked))
void CASFashionTarget::GetVariable(char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C9E2378\n.long 0x38600020\n.long 0x4BE6ADA9\n.long 0x7C7F1B78\n.long 0x38000000\n.long 0x3C60803F\n.long 0x981F0000\n.long 0x3863C8A0\n.long 0x7FC4F378\n.long 0x480A8055\n.long 0x2C030000\n.long 0x40820028\n.long 0x3C60803F\n.long 0x3863C3C8\n.long 0x4BFDE369\n.long 0x7C7E1B78\n.long 0x4BF0C679\n.long 0x38830001\n.long 0x7FE5FB78\n.long 0x7FC3F378\n.long 0x4BE6F4D5\n.long 0x7FE3FB78\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
