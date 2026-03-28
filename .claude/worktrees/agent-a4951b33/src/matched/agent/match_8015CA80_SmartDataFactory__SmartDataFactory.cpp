// 0x8015CA80 (124 bytes)
// SmartDataFactory::SmartDataFactory(void)

class SmartDataFactory { public: void SmartDataFactory(void); };

__attribute__((naked))
void SmartDataFactory::SmartDataFactory(void) {
    asm volatile(".long 0x9421FFD8\n.long 0x7C0802A6\n.long 0xBF810018\n.long 0x9001002C\n.long 0x3D208046\n.long 0x7C7C1B78\n.long 0x39295B20\n.long 0x3BDC0004\n.long 0x3BA00000\n.long 0x913C0000\n.long 0x93BE0004\n.long 0x38600020\n.long 0x4823F855\n.long 0x7C691B78\n.long 0x93BE0008\n.long 0x913E0004\n.long 0x7F83E378\n.long 0x9BBE000C\n.long 0x93A90000\n.long 0x817E0004\n.long 0x93AB0004\n.long 0x813E0004\n.long 0x91290008\n.long 0x817E0004\n.long 0x916B000C\n.long 0x93BC0014\n.long 0x8001002C\n.long 0x7C0803A6\n.long 0xBB810018\n.long 0x38210028\n.long 0x4E800020");
}
