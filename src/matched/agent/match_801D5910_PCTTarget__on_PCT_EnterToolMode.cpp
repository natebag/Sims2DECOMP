// 0x801D5910 (108 bytes)
// PCTTarget::on_PCT_EnterToolMode(void)

class PCTTarget { public: void on_PCT_EnterToolMode(void); };

__attribute__((naked))
void PCTTarget::on_PCT_EnterToolMode(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C6B1B78\n.long 0x800B00B0\n.long 0x810B00A8\n.long 0x1D400014\n.long 0x7D285214\n.long 0x2C090000\n.long 0x41820034\n.long 0x7C08502E\n.long 0x2C000000\n.long 0x41820028\n.long 0x41800024\n.long 0x2C000004\n.long 0x4181001C\n.long 0x38000000\n.long 0x7D635B78\n.long 0x900B00E8\n.long 0x38800000\n.long 0x4800085D\n.long 0x48000008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
