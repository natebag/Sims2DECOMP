// 0x801479BC (120 bytes)
// TreeSimImpl::GetCurrentPrimitive(void)

class TreeSimImpl { public: void GetCurrentPrimitive(void); };

__attribute__((naked))
void TreeSimImpl::GetCurrentPrimitive(void) {
    asm volatile(".long 0x9421FFD8\n.long 0x7C0802A6\n.long 0xBFA1001C\n.long 0x9001002C\n.long 0x81630000\n.long 0x812B0018\n.long 0xA8690048\n.long 0x8009004C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7C7E1B78\n.long 0x83BE0010\n.long 0x48001729\n.long 0x7C641B78\n.long 0xA8BE0002\n.long 0x7FA3EB78\n.long 0x38C10008\n.long 0x4BF63B5D\n.long 0x2C030000\n.long 0x4082000C\n.long 0x3860FFFF\n.long 0x4800000C\n.long 0xA0610008\n.long 0x5463047E\n.long 0x8001002C\n.long 0x7C0803A6\n.long 0xBBA1001C\n.long 0x38210028\n.long 0x4E800020");
}
