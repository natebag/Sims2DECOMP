// 0x80132DD8 (64 bytes)
// ReconBuffer::ReconBuffer(void)

class ReconBuffer { public: void ReconBuffer(void); };

__attribute__((naked))
void ReconBuffer::ReconBuffer(void) {
    asm volatile(".long 0x7C691B78\n.long 0x38000000\n.long 0x39600002\n.long 0x39400001\n.long 0x9169000C\n.long 0x9009002C\n.long 0x91490010\n.long 0x90090000\n.long 0x90090004\n.long 0x90090008\n.long 0x90090014\n.long 0x90090018\n.long 0x9009001C\n.long 0x90090020\n.long 0x90090028\n.long 0x4E800020");
}
