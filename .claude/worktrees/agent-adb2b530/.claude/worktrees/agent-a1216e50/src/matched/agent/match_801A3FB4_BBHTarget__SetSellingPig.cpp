// 0x801A3FB4 (100 bytes)
// BBHTarget::SetSellingPig(bool)

class BBHTarget { public: void SetSellingPig(bool); };

__attribute__((naked))
void BBHTarget::SetSellingPig(bool) {
    asm volatile(".long 0x9421FFD8\n.long 0x7C0802A6\n.long 0x93E10024\n.long 0x9001002C\n.long 0x8003009C\n.long 0x7C9F2378\n.long 0x7C1F0000\n.long 0x41820034\n.long 0x93E3009C\n.long 0x38610008\n.long 0x4BFD9259\n.long 0x3C80803F\n.long 0x38610008\n.long 0x3884DF70\n.long 0x7FE5FB78\n.long 0x38C00000\n.long 0x4BFD9769\n.long 0x38610008\n.long 0x38800002\n.long 0x4BFD9255\n.long 0x8001002C\n.long 0x7C0803A6\n.long 0x83E10024\n.long 0x38210028\n.long 0x4E800020");
}
